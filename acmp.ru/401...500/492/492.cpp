#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const double EPS = 1e-10;

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

    Point operator + (const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    double len() {
        return sqrt(sqr(x) + sqr(y));
    }

    void read() {
        cin >> x >> y;
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
    cin >> v >> t >> d;

    p = p + vec * t;

    double sqd = abs(p.len() - d);
    if (comp(sqd, t * v) <= 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
                                    
    return 0;
}
