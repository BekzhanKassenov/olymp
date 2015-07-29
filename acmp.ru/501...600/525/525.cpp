#include <iostream>
#include <cstdio>

using namespace std;

int n;
long long dp[1010][10];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if ((1 << j) == i)
                dp[i][j] = 1;
            else if ((1 << j) < i)
                dp[i][j] += dp[i - (1 << j)][j];
            
            if (j)
                dp[i][j] += dp[i][j - 1];
        }
    }

    printf("%I64d\n", dp[n][9]);

    return 0;
}
