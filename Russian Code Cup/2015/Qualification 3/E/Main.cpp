/****************************************
**     Solution by Bekzhan Kassenov    **
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

struct Point {
    double x, y;

    Point() { }

    Point(double x, double y) : x(x), y(y) { }

    Point(const Point& p) : x(p.x), y(p.y) { }

    Point operator + (const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    double operator * (const Point& p) const {
        return x * p.y - y * p.x;
    }

    double len() const {
        return sqrt(sqr(x) + sqr(y));
    }
};

struct Line {
    Point p1, p2;

    Line() { }

    Line(const Point& p1, const Point& p2) : p1(p1), p2(p2) { }

    double dist_to(const Point& p) const {
        double base = (p1 - p2).len();
        double area = abs((p - p1) * (p - p2)) / 2;

        return 2 * area / base;
    }
};

int T;
int n;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    return 0;
}
