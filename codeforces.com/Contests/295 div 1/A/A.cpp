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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char let[] = {'A', 'C', 'G', 'T'};
int cnt[4];
char s[MAXN];
int n;

int powmod(int n, int st) {
    int result = 1;

    while (st) {
        if (st & 1) {
            result = (1ll * result * n) % MOD;
        }

        n = (1ll * n * n) % MOD;
        st >>= 1;
    }

    return result;
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);
    gets(s);

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 4; k++) {
            if (let[k] == s[i]) {
                cnt[k]++;
            }
        }
    }

    int num_max = 0;
    int mx = 0;
    for (int i = 0; i < 4; i++) {
        mx = max(cnt[i], mx);
    }

    for (int i = 0; i < 4; i++) {
        if (mx == cnt[i]) {
            num_max++;
        }
    }

    printf("%d\n", powmod(num_max, n));
    
    return 0;
}
