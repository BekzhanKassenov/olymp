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

int v1, v2, t, d;
int res;

bool can(int v, int vv, int tim) {
    return v + tim * d >= vv;
}

int get(int v, int vv, int tim) {
    int res = 0;
    while (tim > 0 && v + d < vv) {
        res += v;
        v += d;
        tim--;
    }

    while (tim > 0) {
        res += v;
        v = min(vv, v + d);
        tim--;
    }

    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d%d", &v1, &v2, &t, &d);

    if (d == 0) {
        printf("%d\n", v1 * t);
        return 0;
    }

    int ans = 0;
    for (int maxv = max(v1, v2); maxv < 10000; maxv++) {
        for (int tt = 0; tt <= t; tt++) {
            if (can(v1, maxv, tt) && can(v2, maxv, t - tt)) {
                ans = max(ans, get(v1, maxv, tt) + get(v2, maxv, t - tt));
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
