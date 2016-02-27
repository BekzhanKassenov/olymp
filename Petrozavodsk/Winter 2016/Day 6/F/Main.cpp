/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

#ifdef Local
# define I64 "%I64d"
#else
# define I64 "%Ld"
#endif

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

int T;
long long Lm, Lg;
struct Point {
    long long x, y;

    Point(long long x = 0, long long y = 0) : x(x), y(y) { }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    Point operator + (const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    long long dot(const Point& p) const {
        return x * p.x + y * p.y;
    }

    long long cross(const Point& p) const {
        return x * p.y - y * p.x;
    }

    long long len() const {
        return sqr(x) + sqr(y);
    }

    Point operator * (long long coeff) {
        return Point(x * coeff, y * coeff);
    }

    bool operator < (const Point& p) const {
       if (x != p.x) {
           return x < p.x;
       }

       return y < p.y;
    }
};

long long max(long long a, long long b, long long c) {
    return max(max(a, b), c);
}

Point p[3];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T--) {
        cin >> Lm >> Lg;

        for (int i = 0; i < 3; i++) {
            cin >> p[i].x >> p[i].y;
        }

        sort(p, p + 3);
        
        bool ok = false;
        do {
            if ((p[0] - p[1]).cross(p[0] - p[2])) {
                long long len = max((p[0] - p[1]).len(), (p[1] - p[2]).len(), (p[2] - p[0]).len());

                if (len <= sqr(Lm) || len <= sqr(Lg)) {
                    ok = true;
                }

                continue;
            }

            Point diff1 = p[1] - p[0];
            Point diff2 = p[2] - p[0];

            long long num = diff1.dot(diff2);
            long long den = diff1.len();

            diff1 = diff1 * num;
            Point center = p[0] * den + diff1;

            long long dist0 = (p[0] * den - center).len();
            long long dist1 = (p[1] * den - center).len();
            long long dist2 = (p[2] * den - center).len();

            if (dist0 <= sqr(Lg) * sqr(den) && dist1 <= sqr(Lg) * sqr(den) && dist2 <= sqr(Lm) * sqr(den)) {
                ok = true;
            }

        } while (next_permutation(p, p + 3) && !ok);

        if (ok) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    
    return 0;
}
