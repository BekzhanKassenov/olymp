#include <iostream>
#include <cstdio>

using namespace std;

int T, x, y, a;

bool check(int xx, int yy) {
    if (xx % a == 0 && (xx - 2) % a == 0 && (yy - 1) % a == 0)
        return true;

    if ((xx - 1) % a == 0 && (yy - 1) % a == 0)
        return true;

    if (xx % a == 0 && (yy - 2) % a == 0)
        return true; 

    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &T);

    while (T--) {
        scanf("%d%d%d", &x, &y, &a);

        putchar('0' + (check(x, y) || check(y, x)));
    }

    return 0;
}
