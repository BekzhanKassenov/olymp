#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1010;

int n, dp[MAXN][MAXN];
char a[MAXN][MAXN];
int ans;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++)
        fgets(a[i], MAXN, stdin);

    for (int i = 0; i < n; i++) {
        dp[i][0] = a[i][0] - '0';
        dp[0][i] = a[0][i] - '0';
        
        ans = max(ans, dp[i][0]);
        ans = max(ans, dp[0][i]);
    }

    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++) {
            if (a[i][j] == '1') {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                ans = max(ans, dp[i][j]);
            }   
        }
     
    printf("%d\n", ans * ans);

    return 0;
}
