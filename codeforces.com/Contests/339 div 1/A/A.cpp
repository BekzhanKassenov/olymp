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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Point {
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) { }

    void read() {
        scanf("%lf%lf", &x, &y);
    }

    double distTo(const Point& a) const {
        return sqrt(sqr(x - a.x) + sqr(y - a.y));
    }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    double operator * (const Point& p) const {
        return x * p.y - y * p.x;
    }

    double operator ^ (const Point& p) const {
        return x * p.x + y * p.y;
    }

    double distTo(const Point& a, const Point& b) const {
        double ans = min(distTo(a), distTo(b));

        if (((b - a) ^ (*this - a)) < 0 || ((a - b) ^ (*this - b)) < 0) {
            return ans;
        }

        double l = a.distTo(b);
        double area = abs((a - *this) * (b - *this));

        ans = min(ans, area / l);

        return ans;
    }
};

int n;
Point p;
Point a[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    p.read();

    for (int i = 0; i < n; i++) {
        a[i].read();
    }

    double mindist = 1e100;
    double maxdist = 0;

    for (int i = 0; i < n; i++) {
        mindist = min(mindist, p.distTo(a[i], a[(i + 1) % n]));
    }

    for (int i = 0; i < n; i++) {
        maxdist = max(maxdist, p.distTo(a[i]));
    }

    double ans = PI * (sqr(maxdist) - sqr(mindist));

    printf("%.14lf\n", ans);

    return 0;
}
