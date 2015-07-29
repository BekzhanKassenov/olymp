/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "mjolnir"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

struct Point {
    double x, y;

    Point() { }

    Point(double x, double y) : x(x), y(y) { }

    Point operator + (const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    Point operator - (const Point& p) const { 
        return (Point(x - p.x, y - p.y));
    }

    double len() {
        return (sqrt(sqr(x) + sqr(y)));
    }

    void make_len(double leng) {
        double cur = len();

        x /= cur;
        y /= cur;

        x *= leng;
        y *= leng;
    }
};

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    double s, x, y, _x, _y;

    cin >> s >> x >> y >> _x >> _y;

    Point p(x - _x, y - _y);

    Point t = Point(-p.y, p.x);

    //cerr << t.x << ' ' << t.y << endl;

    double c = sqr(p.x) + sqr(p.y);

    double d = sqr(c) - 4 * sqr(s);

    if (d < 0 || c < sqrt(d)) {
        cout << -1;
        return 0;
    }

    double a = sqrt((c + sqrt(d)) / 2);
    double b = sqrt(c - sqr(a));

    //cerr << a << ' ' << b << ' ' << c << endl;

    t.make_len(a);

    Point ans1 = Point(x, y) + t;

    t = Point(p.y, -p.x);
    t.make_len(b);

    cerr << t.x << ' ' << t.y << endl;

    Point ans2 = Point(_x, _y) + t;

    printf("%.10lf %.10lf\n%.10lf %.10lf", ans2.x, ans2.y, ans1.x, ans1.y);

    return 0;
}
