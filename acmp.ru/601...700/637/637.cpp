#include <iostream>
#include <cstdio>

using namespace std;

int n, a[10010], k, ans;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &k);

    for (int i = 0; i < n; i++)
        ans += min(k, a[i]);

    printf("%d", ans);

    return 0;
}
