#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 110;
const int MAXSUM = 350;

typedef long long dpres;

dpres mem[MAXN][MAXSUM];
dpres *dp[MAXN];
int n, k;

bool ok(int idx) {
    return - n * k - 1 <= idx && idx <= n * k + 1;
}

void print(dpres ans) {
    printf("%I64d\n", ans);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);

    for (int i = 0; i <= n; i++)
        dp[i] = mem[i] + n * k + 10;

    for (int i = 0; i <= k; i++) {
        dp[1][k] = 1;
        dp[1][-k] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int sum = - n * k - 1; sum <= n * k + 1; sum++) {
            dp[i][sum] = dp[i - 1][sum];

            for (int j = 1; j <= k; j++) {
                if (ok(sum - j))
                    dp[i][sum] += dp[i - 1][sum - j];
                
                if (ok(sum + j))
                    dp[i][sum] += dp[i - 1][sum + j];
            }
        }
    }

    print(dp[n][0]);

    return 0;
}
