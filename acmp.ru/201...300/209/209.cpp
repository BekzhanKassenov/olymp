#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;

int gcd(int a, int b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }

    return a + b;
}

struct Point {
    int x, y;

    Point() { }

    Point(int x, int y) : x(x), y(y) { } 

    void read() {
        scanf("%d%d", &x, &y);
    }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }                                

    ll operator * (const Point& p) const {
        return x * 1ll * p.y - y * 1ll * p.x;
    }
};

int number_of_int_points(const Point& p1, const Point& p2) {
    int lenx = abs(p1.x - p2.x);
    int leny = abs(p1.y - p2.y);

    int g = gcd(lenx, leny);

    return g;
}

ll area(const Point& p1, const Point& p2, const Point& p3) {
    Point l1 = p2 - p1;
    Point l2 = p3 - p1;

    return l2 * l1;
}

int n;
ll S, B;
Point a[1010];

// S = I + B / 2 - 1
// I = S - B / 2 + 1
// 2 I = 2 S - B + 2
// I = (2 S - B + 2) / 2

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        a[i].read();
    }

    for (int i = 0; i < n; i++) {
        S += area(a[0], a[i], a[(i + 1) % n]);
        B += number_of_int_points(a[i], a[(i + 1) % n]);
    }

    printf("%I64d", (S - B + 2) / 2);

    return 0;
}
