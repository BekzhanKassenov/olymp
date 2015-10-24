#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 110;
const int INF = 2000 * 1000 * 1000;

int n, a[MAXN];
int dp[MAXN][MAXN];
int spent[MAXN][MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = INF;
            spent[i][j] = 0;
        }
    }

    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            if (dp[i][j] != INF) {
                if (a[i + 1] > 100) {
                    if (dp[i + 1][j + 1] > dp[i][j] + a[i + 1]) {
                        dp[i + 1][j + 1] = dp[i][j] + a[i + 1];
                        spent[i + 1][j + 1] = spent[i][j];
                    }
                } else {
                    if (dp[i + 1][j] > dp[i][j] + a[i + 1]) {
                        dp[i + 1][j] = dp[i][j] + a[i + 1];
                        spent[i + 1][j] = spent[i][j];
                    }
                }

                if (j > 0) {
                    if (dp[i + 1][j - 1] > dp[i][j]) {
                        dp[i + 1][j - 1] = dp[i][j];
                        spent[i + 1][j - 1] = spent[i][j] + 1;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int j = 1; j <= n; j++) {
        if (dp[n][j] <= dp[n][ans]) {
            ans = j;
        }
    }

    printf("%d\n%d %d\n", dp[n][ans], ans, spent[n][ans]);

    return 0;
}
