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

int n;
long long xa, ya;
long long xb, yb;
long long xt, yt;
long long x[MAXN], y[MAXN];
int p1[MAXN], p2[MAXN];

double dist(long long xx, long long yy, long long _x, long long _y) {
    return sqrt(sqr(xx - _x) + sqr(yy - _y));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%lld%lld", &xa, &ya);
    scanf("%lld%lld", &xb, &yb);
    scanf("%lld%lld", &xt, &yt);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &x[i], &y[i]);
        p1[i] = p2[i] = i;
    }

    sort(p1, p1 + n, [](int idx1, int idx2) {
        double d1 = dist(x[idx1], y[idx1], xt, yt) - dist(x[idx1], y[idx1], xa, ya);
        double d2 = dist(x[idx2], y[idx2], xt, yt) - dist(x[idx2], y[idx2], xa, ya);

        return d1 < d2;
    });

    sort(p2, p2 + n, [](int idx1, int idx2) {
        double d1 = dist(x[idx1], y[idx1], xt, yt) - dist(x[idx1], y[idx1], xb, yb);
        double d2 = dist(x[idx2], y[idx2], xt, yt) - dist(x[idx2], y[idx2], xb, yb);

        return d1 < d2;
    });

    double total = 0;
    for (int i = 0; i < n; i++) {
        total += 2 * dist(x[i], y[i], xt, yt);
    }

    double ans = 2e18;
    for (int i = max(0, n - 20); i < n; i++) {
        for (int j = max(0, n - 20); j < n; j++) {
            if (p1[i] != p2[j]) {
                double temp = total;
                temp -= dist(x[p1[i]], y[p1[i]], xt, yt);
                temp -= dist(x[p2[j]], y[p2[j]], xt, yt);

                temp += dist(x[p1[i]], y[p1[i]], xa, ya);
                temp += dist(x[p2[j]], y[p2[j]], xb, yb);

                ans = min(ans, temp);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        double temp = total;
        temp -= dist(x[p1[i]], y[p1[i]], xt, yt);
        temp += dist(x[p1[i]], y[p1[i]], xa, ya);

        ans = min(ans, temp);
    }

    for (int j = 0; j < n; j++) {
        double temp = total;
        temp -= dist(x[p2[j]], y[p2[j]], xt, yt);
        temp += dist(x[p2[j]], y[p2[j]], xb, yb);

        ans = min(ans, temp);
    }

    printf("%.14lf\n", ans);
    return 0;
}
