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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n, m, upper;
int p2[MAXN][MAXN], p3[MAXN][MAXN];
int dp[MAXN][MAXN][2 * MAXN * 6 + 10];

void clear() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            p2[i][j] = 0;
            p3[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int p = 0; p < upper; p++) {
                dp[i][j][p] = -INF;
            }
        }
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d%d", &n, &m);
        upper = (n + m + 1) * 6 + 10;
        clear();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x;
                scanf("%d", &x);

                while (x % 2 == 0) {
                    p2[i][j]++;
                    x /= 2;
                }

                while (x % 3 == 0) {
                    p3[i][j]++;
                    x /= 3;
                }
            }
        }

        auto update_dp = [](int pi, int pj, int i, int j) {
            for (int ps = 0; ps + p3[i][j] < upper; ps++) {
                int s = ps + p3[i][j];

                if (dp[pi][pj][ps] != -INF) {
                    dp[i][j][s] = max(dp[i][j][s], dp[pi][pj][ps] + p2[i][j]);
                }
            }
        };

        dp[0][0][p3[0][0]] = p2[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0) {
                    update_dp(i - 1, j, i, j);
                }
                if (j > 0) {
                    update_dp(i, j - 1, i, j);
                }
            }
        }

        int ans = 0;
        for (int s = 0; s < upper; s++) {
            if (dp[n - 1][m - 1][s] != -INF) {
                ans = max(ans, min(s, dp[n - 1][m - 1][s]));
            }
        }

        printf("%d\n", ans);
    }
                
    return 0;
}
