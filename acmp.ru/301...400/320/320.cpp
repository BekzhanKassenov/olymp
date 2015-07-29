#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll dp[60];
int n, m;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d%d", &m, &n);

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];

        if (i >= m)
            dp[i] += dp[i - m];
    }

    printf("%I64d", dp[n]);

    return 0;
}
