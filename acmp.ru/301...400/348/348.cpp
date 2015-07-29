#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int sqr(int n) {
    return n * n;
}

struct Point {
    int x, y;

    Point () { }

    Point (int x, int y) : x(x), y(y) { }

    Point(const Point& p) : x(p.x), y(p.y) { }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    int len() const {
        return sqr(x) + sqr(y);
    }

    bool operator == (const Point& p) const {
        return x == p.x && y == p.y;
    }

    bool is_multiple(const Point& p) const {
        double rat = (p.x ? (x + .0) / p.x : (y + .0) / p.y);

        return x == rat * p.x && y == rat * p.y;
    }

    bool belongs(const Point& p1, const Point& p2) {
        Point vec = p2 - p1;
        Point vec1 = *this - p1;

        if (vec * vec1 != 0)
            return false;

        return vec.len() >= (p2 - *this).len() && vec.len() >= vec1.len();
    }
                                                           
    int read() {
        return scanf("%d %d\n", &x, &y);
    }

    int operator * (const Point& p) const {
        return x * p.y - p.x * y;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
                                       
    Point a, b, c, d;
    a.read();
    b.read();
    c.read();
    d.read();

    if (a == c || b == c || a == d || b == d) {
        puts("Yes");
        return 0;
    }

    Point vec1(b - a);
    Point vec2(d - c);

    if (a.belongs(c, d) || b.belongs(c, d) ||
        c.belongs(a, b) || d.belongs(a, b)) {
        puts("Yes");
        return 0;
    }

    if (vec1 == Point(0, 0) || vec2 == Point(0, 0) || vec1.is_multiple(vec2)) {
        puts("No");
        return 0;
    }

    if (((vec1 * (c - a) > 0) ^ (vec1 * (d - a) > 0)) && ((vec2 * (a - c)) > 0) ^ (vec2 * (b - c) > 0))
        puts("Yes");
    else
        puts("No");

    return 0;   
}
