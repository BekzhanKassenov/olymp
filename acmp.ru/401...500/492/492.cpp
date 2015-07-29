#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const double EPS = 1e-9;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int comp(double a, double b) {
    if (fabs(b - a) <= EPS)
        return 0;

    if (a - b > 0)
        return 1;

    return -1;
}

struct Point {
    double x, y;

    Point() { }

    Point(double x, double y) : x(x), y(y) { }

    Point(const Point& p) {
        *this = p;
    }

    Point operator * (double k) const {
        return Point(x * k, y * k);
    }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    Point operator + (const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    double len() {
        return sqrt(sqr(x) + sqr(y));
    }

    void make_len(double nlen) {
        double l = len();

        if (comp(l, 0) != 0) {
            x /= l;
            y /= l;
        } 

        x *= nlen;
        y *= nlen;
    } 

    void read() {
        scanf("%lf%lf", &x, &y);
    } 
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Point p;
    p.read();
    
    Point vec;
    vec.read();

    double v, t, d;
    scanf("%lf%lf%lf", &v, &t, &d);

    p = p + vec * t;

    Point zero(Point(0, 0) - p);

    if (comp(p.len(), d) <= 0) {
        zero.make_len(d - zero.len());
    } else {
        zero.make_len(d);
        zero = p + zero;
    }

    if (comp(zero.len(), t * v) <= 0) {
        cout << "YES";
        return 0;
    } else {
        cout << "NO";
        return 0;
    }
                                    
    return 0;
}