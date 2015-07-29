#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 110;

int n, m, w[maxn], e[maxn], a[maxn], dp[maxn][maxn], ans;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &m);

    for (int i = 0; i < m; i++)
        scanf("%d%d", w + i, e + i);

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", a + i);

    for (int i = 0; i < m; i++)
        dp[0][i] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            for (int k = 0; k < i; k++) 
                for (int l = 0; l < m; l++)
                    if (a[i] - w[j] >= a[k] && a[k] + e[l] <= a[i])
                        dp[i][j] = max(dp[i][j], dp[k][l]);

            dp[i][j]++;
        }
    }

    for (int i = 0; i < m; i++)
        ans = max(dp[n - 1][i], ans);

    printf("%d", ans);

    return 0;
}
