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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Point {
    double x, y;

    Point (double x = 0.0, double y = 0.0) : x(x), y(y) { }

    Point operator + (const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    double operator * (const Point& p) const {
        return x * p.y - y * p.x;
    }

    double len() const {
        return sqrt(sqr(x) + sqr(y));
    }

    void scale(double nlen) {
        double clen = len();
        x /= clen;
        y /= clen;

        x *= nlen;
        y *= nlen;
    }

    void reflect(const Point& p1, const Point& p2) {
        Point vec1 = p2 - p1;
        Point vec2 = *this - p1;

        if (vec1 * vec2 < 0) {
            double mlen = 2.0 * (abs(vec1 * vec2) / vec1.len());
            
            Point delta = Point(-vec1.y, vec1.x);
            delta.scale(mlen);
            
            x += delta.x;
            y += delta.y;
        }
    }
};

istream& operator >> (istream& in, Point& p) {
    in >> p.x >> p.y;
    return in;
}


ostream& operator << (ostream& out, const Point& p) {
    out << setprecision(10) << fixed;
    out << p.x << ' ' << p.y;
    return out;
}

int n;
Point p[MAXN];

int Q;
Point a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> n >> Q;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    while (Q--) {
        cin >> a >> b;

        for (int i = 0; i < n; i++) {
            p[i].reflect(a, b);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << p[i] << endl;
    }

    return 0;
}
