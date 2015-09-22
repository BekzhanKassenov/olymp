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
const int MAXN = 18;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, k;
int a[MAXN];
int g[MAXN][MAXN];
long long dp[1 << MAXN][MAXN];
long long ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < k; i++) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        g[x - 1][y - 1] = c;
    }

    if (m == 1) {
        printf("%d\n", *max_element(a, a + n));
        return 0;
    }

    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = a[i];
    }

    for (int mask = 1; mask < (1 << n); mask++) {
        if (!(mask & (mask - 1))) {
            continue;
        }

        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                continue;
            }
                
            int prmask = mask ^ (1 << i);
            
            for (int j = 0; j < n; j++) {
                if (!(prmask & (1 << j))) {
                    continue;
                }

                dp[mask][i] = max(dp[mask][i], dp[prmask][j] + g[j][i] + a[i]);
            }
        
            if (__builtin_popcount(mask) == m) {
                ans = max(ans, dp[mask][i]);
            }
        }
    }

    printf("%I64d\n", ans);

    return 0;
}
