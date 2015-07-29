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
const int INF = 1000 * 1000 * 1000;
const int maxn = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T, n, m, t, c;
char can[maxn][maxn];
int dp[maxn][maxn];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &T);

    while (T --> 0) {
        scanf("%d%d%d%d\n", &n, &m, &t, &c);

        for (int i = 0; i < n; i++) {
            gets(can[i]);
        }
        
        for (int i = 0; i < n; i++) {
            if (can[i][0] == '1')
                dp[0][i] = t;
            else
                dp[0][i] = INF;
        }

        int mn = t;

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (can[j][i] == '1') {
                    dp[i][j] = mn + t + c;

                    if (can[j][i - 1] == '1')
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + t);
                }
            }

            mn = INF;

            for (int j = 0; j < n; j++) {
                if (can[j][i] == '1')
                    mn = min(mn, dp[i][j]);
            
            }
        }

        printf("%d\n", mn);
    }

    return 0;
}
