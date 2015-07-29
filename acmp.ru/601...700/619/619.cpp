#include <iostream>
#include <cstdio>

using namespace std;

double dp[510][3010];
int n, q;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);                         

    scanf("%d%d", &n, &q);

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int sum = 0; sum <= q; sum++) {
            for (int j = 1; j <= 6 && j <= sum; j++) {
                dp[i][sum] += dp[i - 1][sum - j] / 6.0;
            }
        }
    }

    printf("%.10lf", dp[n][q]);

    return 0;
}
