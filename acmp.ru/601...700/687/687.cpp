#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int INF = 2147483647;
int n, m, a[15][110], dp[15][110];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }

        reverse(a[i], a[i] + m);
    }

    for (int row = 0; row < n; row++)
        dp[row][0] = a[row][0];

    for (int col = 1; col < m; col++) {
        for (int row = 0; row < n; row++) {
            dp[row][col] = dp[row][col - 1] + a[row][col];

            if (row > 0)
                dp[row][col] = min(dp[row][col], dp[row - 1][col - 1] + a[row][col]);

            if (row < n - 1)
                dp[row][col] = min(dp[row][col], dp[row + 1][col - 1] + a[row][col]);
        }
    }

    int pos = 0;

    for (int row = 0; row < n; row++)
        if (dp[row][m - 1] < dp[pos][m - 1])
            pos = row;

    int ans = dp[pos][m - 1];

    for (int i = m - 1; i >= 0; i--) {
        printf("%d ", pos + 1);

        if (i) {
            if (pos && dp[pos - 1][i - 1] + a[pos][i] == dp[pos][i])
                pos--;
            else if (pos < n - 1 && dp[pos + 1][i - 1] + a[pos][i] == dp[pos][i] && dp[pos][i - 1] + a[pos][i] != dp[pos][i])
                pos++;
        }
    }

    printf("\n%d\n", ans);

    return 0;
}                         