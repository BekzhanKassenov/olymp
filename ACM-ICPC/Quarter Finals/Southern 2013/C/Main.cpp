/****************************************
**        Solution by NU PTZ 2016      **
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

const double EPS = 1e-3;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Point {
    double x, y;

    Point(double x = .0, double y = .0) : x(x), y(y) { }

    void read() {
        scanf("%lf%lf", &x, &y);
    }

    Point operator + (const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    Point operator / (double coeff) {
        return Point(x / coeff, y / coeff);
    }

    void rotate(double theta) {
        double tx = cos(theta) * x - sin(theta) * y;
        double ty = sin(theta) * x + cos(theta) * y;

        x = tx, y = ty;
    }

    double distTo(const Point& p) const {
        return sqrt(sqr(x - p.x) + sqr(y - p.y));
    }

    Point& operator -= (const Point& p) {
        x -= p.x;
        y -= p.y;

        return *this;
    }

    void shift(double a, double b) {
        double l = 0;
        if (abs(y) < EPS) {
            l = a;
        } else {
            double k = x / y;
            double yEllipse = sqrt(1 / (sqr(k / b) + sqr(1 / a)));
            double xEllipse = k * yEllipse;
            l = sqrt(sqr(xEllipse) + sqr(yEllipse));
        }

        double coeff = 100 / l;
        x *= coeff;
        y *= coeff;

        //x = (int)(x + .5);
        //y = (int)(y + .5);
    }

    double cross(const Point& p) const {
        return x * p.y - y * p.x;
    }
};

int n;
Point dist1[MAXN], dist2[MAXN];
Point clos1[MAXN], clos2[MAXN];
Point center[MAXN];
vector <tuple <Point, Point, Point, Point> > rect[MAXN];
long long area[MAXN];
map <long long, int> equiv;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        dist1[i].read();
        dist2[i].read();
        clos1[i].read();
        clos2[i].read();

        int cnt;
        scanf("%d", &cnt);
        rect[i].resize(cnt);
        for (auto& tp: rect[i]) {
            get<0>(tp).read();
            get<1>(tp).read();
            get<2>(tp).read();
            get<3>(tp).read();
        }
    }

    for (int i = 0; i < n; i++) {
        center[i] = (dist1[i] + dist2[i]) / 2;

        dist1[i] -= center[i];
        dist2[i] -= center[i];
        clos1[i] -= center[i];
        clos2[i] -= center[i];

        for (auto& tp: rect[i]) {
            get<0>(tp) -= center[i];
            get<1>(tp) -= center[i];
            get<2>(tp) -= center[i];
            get<3>(tp) -= center[i];
        }

        center[i] = Point();

        double theta = -atan2(dist1[i].y, dist1[i].x);

        dist1[i].rotate(theta);
        dist2[i].rotate(theta);
        clos1[i].rotate(theta);
        clos2[i].rotate(theta);

        for (auto& tp: rect[i]) {
            get<0>(tp).rotate(theta);
            get<1>(tp).rotate(theta);
            get<2>(tp).rotate(theta);
            get<3>(tp).rotate(theta);
        }

        center[i].rotate(theta);
    }

    for (int i = 0; i < n; i++) {
        double a = center[i].distTo(clos1[i]);
        double b = center[i].distTo(dist1[i]);

        for (auto& tp: rect[i]) {
            get<0>(tp).shift(a, b);
            get<1>(tp).shift(a, b);
            get<2>(tp).shift(a, b);
            get<3>(tp).shift(a, b);

            area[i] += round(abs((get<0>(tp) - get<1>(tp)).cross(get<2>(tp) - get<1>(tp))));
        }

        if (!equiv.count(area[i])) {
            int num = equiv.size() + 1;
            equiv[area[i]] = num;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", equiv[area[i]]);
    }
    puts("");

    return 0;
}
