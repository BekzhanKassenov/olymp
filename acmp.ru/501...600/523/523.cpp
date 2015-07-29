#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 110;
const int INF = (int)2e9;

int a[maxn], dp[maxn][maxn], n, k, sum[maxn];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            dp[i][j] = INF;
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);

        sum[i] = a[i] + (i ? sum[i - 1] : 0);
    }

    scanf("%d", &k);

    for (int i = 0; i < n; i++) {
        dp[i][1] = sum[i];

        for (int j = 2; j <= k; j++) {
            for (int l = 0; l < i; l++) {
                dp[i][j] = min(dp[i][j], max(dp[l][j - 1], sum[i] - sum[l]));
            }
        }
    }

    /*for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++)
            printf("%10d ", dp[i][j]);
        
        puts("");
    }*/

    printf("%d", dp[n - 1][k]);

    return 0;
}
