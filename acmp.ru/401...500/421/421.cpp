#include <iostream>
#include <cstdio>
 
using namespace std;
 
template <typename T>
inline T sqr(T n) {
    return n * n;
}
 
struct Point {
    int x, y;

    Point() { }

    Point(int x, int y) : x(x), y(y) { }

    int operator * (const Point& p) const {
        return x * p.y - p.x * y;
    }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    void read() {
        scanf("%d%d", &x, &y);
    }
 
    int dist_to(const Point& p) {
        return sqr(x - p.x) + sqr(y - p.y);
    }
};
 
struct Triple {
    int a, b, c;
 
    Triple() { }
 
    Triple(int a, int b, int c) : a(a), b(b), c(c) { }
 
    bool operator < (const Triple& rhs) const {
        if (a != rhs.a)
            return a < rhs.a;
 
        if (b != rhs.b)
            return b < rhs.b;
 
        return c < rhs.c;
    }
 
    bool operator != (const Triple& rhs) const {
        return *this < rhs || rhs < *this;
    }
};
 
void minimize(Triple& t) {
    Triple temp(t.b, t.c, t.a);
 
    if (temp < t)
        t = temp;
 
    temp = Triple(temp.b, temp.c, temp.a);
 
    if (temp < t)
        t = temp;
}
 
int n;
Point a, b, c;
Triple s, t;
 
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    scanf("%d", &n);
 
    a.read();
    b.read();
    c.read();

    if ((b - a) * (c - a) < 0)
        swap(b, c);

    s = Triple(a.dist_to(b),
               b.dist_to(c),
               c.dist_to(a));
 
    minimize(s);

    for (int i = 0; i < n - 1; i++) {
        a.read();
        b.read();
        c.read();

        if ((b - a) * (c - a) < 0)
            swap(b, c);
 
        t = Triple(a.dist_to(b), 
                   b.dist_to(c), 
                   c.dist_to(a));
 
        minimize(t);
 
        if (s != t) {
            puts("NO");
            return 0;
        }
    }
 
    puts("YES");
 
    return 0;
}