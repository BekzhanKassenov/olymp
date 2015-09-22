#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 5010;

int n, a[MAXN], b[MAXN], c[MAXN];
int dp[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = n; i > 0; i--) {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + a[i];

        if (i > 1) {
            dp[i] = min(dp[i], dp[i - 2] + b[i]);
        }

        if (i > 2) {
            dp[i] = min(dp[i], dp[i - 3] + c[i]);
        }
    }

    printf("%d\n", dp[n]);

    return 0;
}
