#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int n, a[110], S, s;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &S);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        s += a[i];

        if (s > S) {
            printf("%d\n", i);
            return 0;
        }
    }

    printf("%d\n", n);

    return 0;
}
