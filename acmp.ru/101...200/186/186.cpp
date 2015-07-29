#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int INF = 2000 * 1000 * 1000;
const int maxn = 1010;

int n, a[maxn], dp[maxn];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);

    sort(a + 1, a + n + 1);

    for (int i = 2; i <= n; i++) {
        dp[i] = INF;

        for (int j = i - 1; j >= 1; j--) {
            if (j == 2)
                continue;

            dp[i] = min(dp[i], max(a[i] - a[j], dp[j - 1]));
        }
    }

    printf("%d\n", dp[n]);

    return 0;
}
