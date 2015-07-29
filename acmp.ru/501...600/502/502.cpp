#include <iostream>
#include <cstdio>

using namespace std;

int n;
int a[51][51], dp[51][51];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    int ans = 0;

    for (int col = 1; col <= n; col++) {
        for (int sum = 0; sum <= n; sum++) {
            for (int row = 1; row <= sum; row++) {
                for (int pre_col = 0; pre_col < col; pre_col++)
                    dp[col][sum] = max(dp[col][sum], dp[pre_col][sum - row] + a[row][col]);
            }
        }

        ans = max(ans, dp[col][n]);
    }

    printf("%d\n", ans);

    return 0;
}
