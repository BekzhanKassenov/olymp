#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 110;
const int INF = 2000 * 1000 * 1000;

int dp[maxn][maxn], n, a[maxn];
bool calced[maxn][maxn];

int calc(int l, int r) {
    if (r - l == 1)
        return 0;

    if (calced[l][r])
        return dp[l][r];

    calced[l][r] = true;
    int& ans = dp[l][r];
    ans = INF;

    for (int i = l + 1; i < r; i++) {
        ans = min(ans, calc(l, i) + calc(i, r) + a[i] * (a[l] + a[r]));
    }

    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if (n <= 2) {
        puts("0");
        return 0;
    }

    printf("%d\n", calc(0, n - 1));

    return 0;
}
