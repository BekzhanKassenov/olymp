#include <iostream>
#include <cstdio>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int n, k;
    scanf("%d%d", &n, &k);

    int done = 1;
    int ans = 0;
    while (done < k && done < n) {
        done = min(2 * done, n);
        ans++;
    }

    if (done < n) {
        ans += (n - done + (k - 1)) / k;
    }

    printf("%d\n", ans);

    return 0;
}
