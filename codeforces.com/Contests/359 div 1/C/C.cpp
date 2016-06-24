/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define by(x, T) [](const T& a, const T& b) { return a.x < b.x; }

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

int T;
int n;

struct Point {
    long long x, y, z;

    void read() {
        scanf("%lld%lld%lld", &x, &y, &z);
    }
};

Point p[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            p[i].read();
        }

        long long xmin = p[0].x, xmax = p[0].x;
        long long ymin = p[0].y, ymax = p[0].y;
        long long zmin = p[0].z, zmax = p[0].z;

        for (int i = 1; i < n; i++) {
            xmin = min(xmin, p[i].x);
            xmax = max(xmax, p[i].x);

            ymin = min(ymin, p[i].y);
            ymax = max(ymax, p[i].y);

            zmin = min(zmin, p[i].z);
            zmax = max(zmax, p[i].z);
        }

        long long x = (xmin + xmax) / 2;
        long long y = (ymin + ymax) / 2;
        long long z = (zmin + zmax) / 2;
                
        printf("%lld %lld %lld\n", x, y, z);

    }

    return 0;
}
