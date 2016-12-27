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
const long double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Point {
    int x, y;
    int idx;

    long double angle() const {
        long double ans = atan2(y, x);
        if (ans < 0) {
            ans += 2 * PI;
        }

        return ans;
    }
    
    bool operator < (const Point& p) const {
        return angle() < p.angle();
    }
};

int n;
Point p[MAXN];
long double ans = 10000;
int ansi;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &p[i].x, &p[i].y);
        p[i].idx = i + 1;
    }

    sort(p, p + n);

    for (int i = 0; i < n; i++) {
        long double ang = abs(p[i].angle() - p[(i + 1) % n].angle());
        if (ang > PI) {
            ang = 2 * PI - ang;
        }

        if (ang < ans) {
            ans = ang;
            ansi = i;
        }
    }

    printf("%d %d\n", p[ansi].idx, p[(ansi + 1) % n].idx);

    return 0;
}
