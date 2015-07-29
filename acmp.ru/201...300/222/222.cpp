#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double PI = acos(-1.0);
const int MAXN = 50010;

typedef enum {OPEN, CLOSE} sec;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Point {
    double x, y;

    const static Point X;
    const static Point Y;

    Point() { }

    Point(double x, double y) : x(x), y(y) { }

    Point operator + (const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    Point operator - () const {
        return Point(-x, -y);
    }

    double operator * (const Point& p) const {
        return x * p.y - p.x * y;
    }

    bool operator < (const Point& p) const {
        return (*this) * p > 0;
    }

    double len() const {
        return sqrt(sqr(x) + sqr(y));
    }

    void make_len(double nlen) {
        double l = len();

        x /= l;
        y /= l;

        x *= nlen;
        y *= nlen;
    }

    void read() {
        scanf("%lf%lf", &x, &y);
    }
};

const Point Point::X = Point(100, 0);
const Point Point::Y = Point(0, 100);

Point p, center, temp;
double R;
pair <double, sec> a[4 * MAXN];
int last;
int n;

double get_angle(const Point& p) {
}

void add_range(const Point& l, const Point& r) {
    double anglel = get_angle(l);
    double angler = get_angle(r);

    if (Point::X < r && l < Point::X) {
        a[last++] = make_pair(0, OPEN);
        a[last++] = make_pair(angler, CLOSE);

        a[last++] = make_pair(anglel, OPEN);
        a[last++] = make_pair(2 * PI, CLOSE);
    } else {
        a[last++] = make_pair(anglel, OPEN);
        a[last++] = make_pair(angler, CLOSE);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        p.read();
        scanf("%lf", &R);

        temp = p - center;
        temp.make_len(R);

        Point rad = Point(temp.y, -temp.x);
        
        Point l = rad;
        Point r = -rad;

        add_range(l, r);
    }

    return 0;
}
