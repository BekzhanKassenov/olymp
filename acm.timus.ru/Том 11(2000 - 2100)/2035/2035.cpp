#include <iostream>
#include <cstdio>

using namespace std;

int x, y, c;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &x, &y, &c);

    if (x + y < c) {
        puts("Impossible");
        return 0;
    }

    if (x >= c) {
        printf("%d %d\n", c, 0);
        return 0;
    }

    if (y >= c) {
        printf("%d %d\n", 0, c);
        return 0;
    }

    printf("%d %d\n", x, c - x);

    return 0;   
}
