#include <iostream>
#include <cstdio>

using namespace std;

int a[31], n, l, r;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &l, &r);

        l--, r--;

        for (int j = l; j <= r; j++)
            a[j]++;
    }

    for (int i = 0; i < 31; i++)
        if (a[i] == n) {
            puts("YES");
            return 0;
        }

    puts("NO");

    return 0;
}
