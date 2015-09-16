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

const double EPS = 1e-11;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 200010;
const int MAGIC = 200;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, x;
double a[MAXN];

void update(double& res, double nval) {
    res = max(res, nval);
}

double f(double x) {
    double result = 0;

    double negmax = 0, negmin = 0;
    double posmax = 0, posmin = 0;

    double pref = 0;

    for (int i = 0; i < n; i++) {
        pref += a[i] - x;

        update(result, abs(pref - posmax));
        update(result, abs(pref - posmin));
        update(result, abs(pref - negmax));
        update(result, abs(pref - negmin));
        update(result, abs(pref));

        if (pref > 0) {
            posmax = max(posmax, pref);
            posmin = min(posmin, pref);
        }

        if (pref < 0) {
            negmax = max(negmax, pref);
            negmin = min(negmin, pref);
        }
    }

    return result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        a[i] = x;
    }

    double r = 1e9;
    double l = -r;

    for (int iter = 0; iter < MAGIC; iter++) {
        double m1 = l + (r - l) / 3.0;
        double m2 = r - (r - l) / 3.0;

        if (f(m1) < f(m2)) {
            r = m2;
        } else {
            l = m1;
        }
    }

    printf("%.14lf\n", f(l));

    return 0;
}
