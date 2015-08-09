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
const int MAXN = 500010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, q, x;
int ans, cnt;
int a[MAXN], dp[MAXN];
bool taken[MAXN];
vector <int> fact[MAXN];

void factorize(int num, vector <int>& vec) {
    vec.clear();
    vec.push_back(1);

    for (int i = 2; num > 1; i++) {
        if (num % i == 0) {
            vec.push_back(i);

            while (num % i == 0) {
                num /= i;
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &q);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        factorize(a[i], fact[i]);
    }

    while (q--) {
        scanf("%d", &x);

        vector <int>& vec = fact[x - 1];

        int size = vec.size();

        int res = 0;
        for (int mask = 0; mask < (1 << size); mask++) {
            int sum = 0;

            for (int i = 0; i < size; i++) {
                if (mask & (1 << i)) {
                    sum += dp[vec[i]];
                }
            }
        
            if (__builtin_popcount(mask) & 1) {
                res += sum;
            } else {
                res -= sum;
            }
        }

        for (int i = 0; i < 6; i++) {
            cout << dp[i] << ' ';
        }
        cout << endl;

        for (int i = 0; i < size; i++) {
            if (taken[x - 1]) {
                dp[vec[i]]--;
            } else {
                dp[vec[i]]++;
            }
        }

        taken[x - 1] ^= 1;

        if (taken[x - 1]) {
            ans += cnt - res;
            cnt++;
        } else {
            ans -= cnt - res;
            cnt--;
        }

        printf("%d\n", ans);
    }

    return 0;
}
