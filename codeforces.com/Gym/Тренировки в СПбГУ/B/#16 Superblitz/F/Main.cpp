/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int gcd(int a, int b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }

    return a + b;
}

struct Point {
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) { }

    void read() {
        cin >> x >> y;
    }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    bool operator < (const Point& p) const {
        return (x < p.x || (p == p.x && y < p.y));
    }

    bool operator == (const Point& p) const {
        return x == p.x && y == p.y;
    }

    void norm() {
        int g = gcd(abs(x), abs(y));

        x /= g;
        y /= g;
    }

    double dot(const Point& p) const {
        return x * p.x + y * p.y;
    }

    double cross(const Point& p) const {
        return x * p.y - y * p.x;
    }

    bool between(const Point& l, const Point& r) {
        if (*this == l || *this == r) {
            return true;
        }

        Point vec1 = *this - l;
        Point vec2 = r - *this;

        return vec1.cross(vec2) == 0 && vec1.dot(vec2) > 0;
    }
};

int sign(double val) {
    return (val > 0) - (val < 0);
}

Point a, b;
Point c, d;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    a.read();
    b.read();
    c.read();
    d.read();

    Point vec1 = b - a;
    Point vec2 = d - c;

    if (vec1.cross(vec2) == 0) {
        if (c.between(a, b) || d.between(a, b) || a.between(c, d) || b.between(c, d)) {
            puts("YES");
        } else {
            puts("NO");
        }
    } else {
        if (sign(vec1.cross(c - a)) != sign(vec1.cross(d - a)) && sign(vec2.cross(a - c)) != sign(vec2.cross(b - c))) {
            puts("YES");
        } else {
            puts("NO");
        }
    }

    return 0;
}
