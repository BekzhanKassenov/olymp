#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }

    return a + b;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int x, y, _x, _y;

    scanf("%d%d%d%d", &x, &y, &_x, &_y);

    int lenx = abs(x - _x);
    int leny = abs(y - _y);

    int g = gcd(lenx, leny);
    lenx /= g;
    leny /= g;

    printf("%d", g + 1);

    return 0;
}

