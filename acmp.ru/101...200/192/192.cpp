#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int n, p[10010];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    int pos = n - 1;

    while (pos >= 0 && p[pos] > p[pos + 1]) {
        pos--;
    }

    if (pos == 0) {
        for (int i = 1; i <= n; i++) {
            printf("%d%c", i, " \n"[i == n]);
        }

        return 0;
    }

    int pos1 = n;

    while (p[pos] > p[pos1]) {
        pos1--;
    }

    swap(p[pos], p[pos1]);
    reverse(p + pos + 1, p + n + 1);

    for (int i = 1; i <= n; i++) {
        printf("%d%c", p[i], " \n"[i == n]);
    }

    return 0;
}
