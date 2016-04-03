/****************************************
**        Solution by NU PTZ 2016      **
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
const int MAXN = 300010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int m, n, d;
double c[MAXN];
double x[MAXN];
int l[MAXN], r[MAXN];

double dist(double a, double b) {
    return sqr(a - b) + 1;
}

int get_closest(double x) {
    int pos = lower_bound(c, c + m, x) - c;

    if (pos == m) {
        return m - 1;
    }

    int ans = pos;
    for (int i = max(pos - 2, 0); i < min(pos + 3, m); i++) {
        if (dist(c[i], x) < dist(c[ans], x)) {
            ans = i;
        }
    }

    return ans;
}

int get_left(double x, int init) {
    int ll = 0, rr = init;

    int ans = init;
    while (ll <= rr) {
        int mid = (ll + rr) / 2;
        if (dist(c[mid], x) <= sqr(d)) {
            ans = mid;
            rr = mid - 1;
        } else {
            ll = mid + 1;
        }
    }

    return ans;
}

int get_right(double x, int init) {
    int ll = init, rr = m - 1;

    int ans = init;
    while (ll <= rr) {
        int mid = (ll + rr) / 2;
        if (dist(c[mid], x) <= sqr(d)) {
            ans = mid;
            ll = mid + 1;
        } else {
            rr = mid - 1;
        }
    }

    return ans;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &m, &n, &d);

    for (int i = 0; i < m; i++) {
        scanf("%lf", &c[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    for (int i = 0; i < n; i++) {
        int closest = get_closest(x[i]);

        l[i] = get_left(x[i], closest);
        r[i] = get_right(x[i], closest);
    }

    int pos = 0;

    double ans = 0;
    for (int i = 0; i < n; i++) {
        if (pos < l[i]) {
            ans += c[l[i]] - c[pos];
            pos = l[i];
        } else if (pos > r[i]) {
            ans += c[pos] - c[r[i]];
            pos = r[i];
        }
    }

    printf("%.5lf\n", ans);
    
    return 0;
}
