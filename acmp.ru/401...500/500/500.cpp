#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 10010;
pair <int, int> a[maxn];
int n, dp[maxn];
bool calced[maxn];

int go(int pos) {
    if (pos > n)
        return 0;

    if (n - pos == 3)
        return a[pos].second + a[pos + 1].second;

    if (n - pos < 3)
        return a[pos].second;

    if (calced[pos])
        return dp[pos];

    calced[pos] = true;

    dp[pos] = min(a[pos].second + go(pos + 2), a[pos].second + a[pos + 1].second + go(pos + 3));

    return dp[pos];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d%d", &a[i].first, &a[i].second);

    sort(a, a + n);
    reverse(a, a + n);

    printf("%d", go(0));

    return 0;
}
