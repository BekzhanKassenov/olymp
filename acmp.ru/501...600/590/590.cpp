#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Point {
    long long x, y, z;

    Point() { }

    Point(long long x, long long y, long long z) : x(x), y(y), z(z) { }

    void read() {
        scanf("%I64d%I64d%I64d", &x, &y, &z);
    }

    Point operator + (const Point& p) const {
        return Point(x + p.x, y + p.y, z + p.z);
    }

    bool operator < (const Point& p) const {
        if (x != p.x)
            return x < p.x;

        if (y != p.y)
            return y < p.y;

        return z < p.z;
    }

    bool operator != (const Point& p) const {
        return *this < p || p < *this;
    }
};

int n;
Point a[1010];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        a[i].read();
    }

    sort(a, a + n);

    Point mid = a[0] + a[n - 1];

    int l = 0, r = n - 1;

    while (l <= r) {
        Point temp = a[l++] + a[r--];

        if (temp != mid) {
            puts("No");
            return 0;
        }
    }

    puts("Yes");
    
    return 0;
}
