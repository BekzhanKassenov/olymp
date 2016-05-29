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
const int MAXN = 10010;
const double R = 1000.0;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
tuple <int, int, int> points[MAXN];

double area(double _x1, double _y1,
            double _x2, double _y2,
            double _x3, double _y3) {
    
    double xVec1 = _x1 - _x2;
    double yVec1 = _y1 - _y2;

    double xVec2 = _x3 - _x2;
    double yVec2 = _y3 - _y2;

    double prod = xVec1 * yVec2 - xVec2 * yVec1;

    return abs(prod) / 2;
}

void convert(tuple <int, int, int> tp, double& x, double& y) {
    double deg = std::get<0>(tp) + std::get<1>(tp) / 60.0 + std::get<2>(tp) / 3600.0;
    double rad = deg * PI / 180.0;

    x = R * cos(rad);
    y = R * sin(rad);
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        points[i] = tuple <int, int, int>(a, b, c);
    }

    sort(points, points + n);
    
    double ans = PI * sqr(R);

    for (int i = 0; i < n; i++) {
        double _x1, _y1;
        double _x2, _y2;
        double _x3, _y3;

        convert(points[i], _x1, _y1);
        convert(points[(i + 1) % n], _x2, _y2);
        convert(points[(i + 2) % n], _x3, _y3);

        ans = min(ans, area(_x1, _y1, _x2, _y2, _x3, _y3));
    }

    printf("%.10lf\n", ans);
    
    return 0;
}
