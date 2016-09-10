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

    void read() {
        cin >> x >> y;
    }
};

Point p1, p2;
Point v1, v2;

double f(double t) {
    double x = (p1.x + v1.x * t) - (p2.x + v2.x * t);
    double y = (p1.y + v1.y * t) - (p2.y + v2.y * t);
    
    return sqrt(sqr(x) + sqr(y));
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    p1.read();
    p2.read();

    v1.read();
    v2.read();

    double l = 0, r = 1e10;
    for (int i = 0; i < 1000; i++) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;

        if (f(m1) < f(m2)) {
            r = m2;
        } else {
            l = m1;
        }
    }

    if (f(l) > f(0)) {
        l = 0;
    }

    printf("%.14lf\n", f(l));

    return 0;
}
