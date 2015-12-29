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

int xp, yp, zp;
int x, y, h, r;

double calc() {
    double num = sqr(r);
    double den = sqr(x - xp) + sqr(y - yp);

    assert(-1 <= 2 * num / den - 1 && 2 * num / den - 1 <= 1);
    double beta = acos(2 * num / den - 1);

    return beta * r;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &xp, &yp, &zp);
    scanf("%d%d%d%d", &x, &y, &h, &r);

    double ans = 0;

    if (zp < 0 || zp > r) {
        ans += PI * sqr(r);
    }

    if (sqr(x - xp) + sqr(y - yp) > sqr(r)) {
        ans += calc() * h;
    }

    printf("%.10lf\n", ans);

    return 0;
}
