#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 5010;

int n, a[maxn], b[maxn], c[maxn], dp[maxn];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", a + i, b + i, c + i);
    }   

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + a[i];

        if (i > 1)
            dp[i] = min(dp[i], dp[i - 2] + b[i - 1]);
        
        if (i > 2)
            dp[i] = min(dp[i], dp[i - 3] + c[i - 2]);
    }

    printf("%d\n", dp[n]);

    return 0;
}
