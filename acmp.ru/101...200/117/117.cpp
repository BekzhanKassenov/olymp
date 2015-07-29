#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1010;

int sqr(int n) {
    return n * n;
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

    int operator * (const Point& p) const {
        return x * p.y - y * p.x;
    }

    int len() const {
        return sqr(x) + sqr(y);
    }
};

int n, size;
Point a[MAXN], mn, st[MAXN];

bool cmpsort(const Point& p1, const Point& p2) {
    if ((p1 - mn) * (p2 - mn) != 0) {
        return (p1 - mn) * (p2 - mn) < 0;
    }

    return (p1 - mn).len() < (p2 - mn).len();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Point aa(1, 0);
    Point bb(0, 1);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        a[i].read();
    }

    mn = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i].x < mn.x || (a[i].x == mn.x && a[i].y < mn.y)) {
            mn = a[i];
        }
    }

    sort(a, a + n, cmpsort);

    st[size++] = a[0];

    for (int i = 1; i < n; i++) {
        while (size > 1 && (a[i] - st[size - 2]) * (st[size - 1] - st[size - 2]) <= 0) {
            size--;
        }

        st[size++] = a[i];
    }

    double area = 0;

    for (int i = 0; i < size; i++) {
        area += abs(((st[i] - st[0]) * (st[(i + 1) % size] - st[0]))) / 2.0;
    }

    printf("%d\n", (int)(area + 0.5));

    return 0;
}
