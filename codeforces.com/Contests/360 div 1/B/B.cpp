/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k;
int c[MAXN];
bool dp[1 << 10];

vector <int> divs;
vector <int> power;

vector <int> mask;

int get_mask(int num) {
    int mask = 0;
    for (size_t i = 0; i < divs.size(); i++) {
        int d = divs[i];
        if (num % d == 0) {
            int cnt = 0;
            while (num % d == 0) {
                cnt++;
                num /= d;
            }

            if (cnt >= power[i]) {
                mask |= 1 << i;
            } else {
                return -1;
            }   
        }
    }

    //if (num > 1) {
    //    return -1;
    //}
    
    return mask;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    int num = k;
    for (int i = 2; i * i <= k; i++) {
        if (num % i == 0) {
            int cnt = 0;

            while (num % i == 0) {
                cnt++;
                num /= i;
            }

            divs.push_back(i);
            power.push_back(cnt);
        }
    }

    if (num > 1) {
        divs.push_back(num);
        power.push_back(1);
    }

    for (int i = 0; i < n; i++) {
        int m = get_mask(c[i]);
        if (m != -1) {
            mask.push_back(m);
        }
    }

    sort(all(mask));
    mask.resize(unique(all(mask)) - mask.begin());
    
    dp[0] = true;
    for (int m: mask) {
        for (int i = 0; i < (1 << divs.size()); i++) {
            if (dp[i] && (i & m) == 0) {
                dp[i | m] = true;
            }
        }
    }

    if (dp[(1 << divs.size()) - 1]) {
        puts("Yes");
    } else {
        puts("No");
    }

    return 0;
}
