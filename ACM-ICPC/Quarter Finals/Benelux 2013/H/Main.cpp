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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Point {
    double x, y;

    Point(double x = 0.0, double y = 0.0) : x(x), y(y) { }

    Point operator + (const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    double dot(const Point& p) const {
        return x * p.x + y * p.y;
    }

    double cross(const Point& p) const {
        return x * p.y - y * p.x;
    }

    double distTo(const Point& p) const {
        return sqrt(sqr(x - p.x) + sqr(y - p.y));
    }

    void makeLen(double nlen) {
        double len = distTo(Point(0, 0));

        x /= len;
        y /= len;

        x *= nlen;
        y *= nlen;
    }
};  

ostream& operator << (ostream& out, const Point& p) {
    out << p.x << ' ' << p.y;
    return out;
}

int sign(double n) {
    return (n > 0) - (n < 0);
}

bool intersection(const Point& C, const Point& vec, const Point& A, const Point& B, Point& ans) {
    Point CA = A - C;
    Point CB = B - C;

    if (vec.cross(CA) == 0) {
        ans = A;
        return true;
    }

    if (vec.cross(CB) == 0) {
        ans = B;
        return true;
    }

    if (sign(vec.cross(CA)) == sign(vec.cross(CB))) {
        return false;
    }

    double x = abs(vec.cross(CA) / vec.cross(CB));

    double nlen = (A.distTo(B) * x) / (x + 1);
    Point AB = B - A;
    AB.makeLen(nlen);

    ans = A + AB;
    return true;
}

Point p[MAXN];
int T, n;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    cin >> T;

    while (T--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> p[i].x >> p[i].y;
        }

        Point C((p[0].x + p[1].x) / 2.0, (p[0].y + p[1].y) / 2.0);

        double area = 0;
        for (int i = 0; i < n; i++) {
            area += (p[i] - C).cross(p[(i + 1) % n] - C) / 2.0;
        }

        double area1 = area;

        Point CB = p[1] - C;
        Point perp(-CB.y, CB.x);

        Point vec1 = CB + perp;

        for (int i = 1; i < n; i++) {
            Point inter;

            if (intersection(C, vec1, p[i], p[(i + 1) % n], inter)) {
                for (int j = 1; j < i; j++) {
                    area1 -= (p[j] - C).cross(p[(j + 1) % n] - C) / 2.0;
                }

                area1 -= (p[i] - C).cross(inter - C) / 2.0;

                /*
                cerr << inter << endl;
                cerr << p[i] - C << ' ' << inter - C << ' ' << endl;
                cerr << (p[i] - C).cross(inter - C) / 2.0 << endl;
                */
                break;
            }
        }

        Point CA = p[0] - C;
        Point vec2 = CA + perp;

        for (int i = 0; i < n; i++) {
            Point inter;

            if (intersection(C, vec2, p[(-i - 1 + n) % n], p[(-i + n) % n], inter)) {
                for (int j = -i; j < 0; j++) {
                    area1 -= (p[(j + n) % n] - C).cross(p[(j + n + 1) % n] - C) / 2.0;
                }

                area1 -= (inter - C).cross(p[(-i + n) % n] - C) / 2.0;

                break;
            }
        }

        cout << setprecision(10) << fixed;
        cout << area1 / area << endl;
    }
    
    return 0;
}
