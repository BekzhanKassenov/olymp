#include <iostream>
#include <cstdio>

using namespace std;

int n, k;
int a[maxn];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s += a[i];
    }

    return 0;
}
