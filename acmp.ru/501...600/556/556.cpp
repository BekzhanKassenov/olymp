#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n;
double dp[110][110], p[110];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%lf", &p[i]);

    dp[1][0] = p[1];
    dp[1][1] = 1 - p[1];

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = dp[i - 1][j - 1] * (1 - p[i]) + dp[i - 1][j] * p[i];
        }
    }

    double ans = 0;

    for (int i = 0; i <= n; i++) {
        if (i % 2 == 0)
            ans += dp[n][i];
    }

    printf("%.10lf", ans);

    return 0;
}
