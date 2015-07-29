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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int DSUparent[MAXN];
int size[MAXN];

int get_parent(int v) {
    if (DSUparent[v] == v) {
        return v;
    }

    return DSUparent[v] = get_parent(DSUparent[v]);
}

void unite(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a == b) {
        return;
    }

    if (size[a] > size[b]) {
        DSUparent[b] = a;
        size[a] += size[b];
    } else {
        DSUparent[a] = b;
        size[b] += size[a];
    }
}

struct Point {
    double x, y;

    Point() { }

    Point(double x, double y) : x(x), y(y) { }

    void read() {
        scanf("%lf%lf", &x, &y);
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

    bool operator == (const Point& p) const {
        return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
    }
};

struct Segment {
    Point a, b;

    void read() {
        a.read();
        b.read();
    }

    bool contains(const Point& p) const {
        Point p1 = p - a;
        Point p2 = b - p;

        return a == p || p == b || (fabs(p1 * p2) < EPS && (p1 ^ p2) > EPS);
    }
};

bool overlaps(Segment l, Segment r) {
    if (fabs((l.a - l.b) * (r.a - r.b)) > EPS) {
        return false;
    }

    return l.contains(r.a) || l.contains(r.b) ||
           r.contains(l.a) || r.contains(l.b);
}

int n, ans;
Segment a[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    for (scanf("%d", &n); n != 0; scanf("%d", &n)) {
        for (int i = 0; i < n; i++) {
            size[i] = 1;
            DSUparent[i] = i;
            a[i].read();
        }

        ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (overlaps(a[i], a[j])) {
                    unite(i, j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (get_parent(i) == i) {
                ans++;
            }
        }

        printf("%d\n", ans);
    }
    
    return 0;
}

