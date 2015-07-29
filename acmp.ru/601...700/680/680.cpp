#include <iostream>
#include <cstdio>

using namespace std;

typedef unsigned long long ll;

int n;
ll dp[55][3];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    dp[0][0] = dp[0][1] = dp[0][2] = 1;

    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
        dp[i][2] = dp[i - 1][0] + dp[i - 1][1];
    }

    printf("%I64d", dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2]);
}
