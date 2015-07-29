#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1010;

int n;
long long a[MAXN], ans;
long long prefsum, suffsum;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
        suffsum += a[i];
    }

    for (int i = 0; i < n; i++) {
        suffsum -= a[i];
        ans += prefsum * a[i] * suffsum;
        prefsum += a[i];
    }

    printf("%I64d\n", ans);

    return 0;
}
