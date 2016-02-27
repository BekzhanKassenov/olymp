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

    long long lensqr() const {
        return sqr(x) + sqr(y);
    }

    Point& operator *= (long long coeff) {
        x *= coeff;
        y *= coeff;
        
        return *this;
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

                if (len <= sqr(LM) || len <= sqr(LG)) {
                    ok = true;
                }

                continue;
            }

            if ((p[2] - p[0]).dot(p[1] - p[0]) < 0) {
                Point diff = p[0] - p[1];
                long long num = (p[2] - p[0]).dot(diff);
                long long den = diff.lensqr();

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
