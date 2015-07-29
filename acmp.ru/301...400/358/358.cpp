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

int points_on_segment(int x, int y, int _x, int _y) {
    return gcd(abs(x - _x), abs(y - _y)) + 1;
}

int x[3], y[3];
long long ans;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; i < 3; i++)
        scanf("%d%d", &x[i], &y[i]);

    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            ans += points_on_segment(x[i], y[i], x[j], y[j]);
        }
    }

    ans -= 3;

    printf("%I64d\n", ans);

    return 0;
}
