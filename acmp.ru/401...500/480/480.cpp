#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int n, k, dp[200][100], a[200], sum[200];
bool calced[200][100];

int go(int pos, int cnt) {
    if (pos == 0)
        return 0;

    if (calced[pos][cnt])
        return dp[pos][cnt];

    calced[pos][cnt] = true;
    int& ans = dp[pos][cnt];
    int cur = 0;

    for (int i = 1; i <= cnt && pos - i >= 0; i++) {
        cur += a[pos - i + 1];
        
        ans = max(ans, cur + sum[pos - i] - go(pos - i, i));
    }

    return ans;
} 

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d ", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d ", &a[i]);

    reverse(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++)
        sum[i] = a[i] + sum[i - 1];

    scanf("%d\n", &k);

    printf("%d\n", go(n, k));                       

    return 0;
}
