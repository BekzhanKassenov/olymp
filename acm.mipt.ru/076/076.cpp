#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int INF = 2000 * 1000 * 1000;
const int MAXN = 2010;

char s[MAXN];
int n;
int dp[MAXN][MAXN / 2 + 10];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    gets(s + 1);
    n = strlen(s + 1);

    if (n & 1) {
        puts("NO");
        return 0;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n / 2 + 1; j++) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        if (s[i + 1] == '(') {
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][0]);
        } else {
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + 1);
        }
        
        for (int j = 1; j <= n / 2 + 1; j++) {
            if (s[i + 1] == '(') {
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
                dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j] + 1);

            } else {
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 1);
                dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j]);
            }
        }
    }

    printf("%d\n", dp[n][0]);

    return 0;
}
