#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 1010;

int n, ans;
int a[MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);

    for (int i = 0; i + 1 < n; i++) {
        if (a[i] != 0) {
            ans += a[i];
            a[i + 1] -= a[i];
            a[i] = 0;
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
