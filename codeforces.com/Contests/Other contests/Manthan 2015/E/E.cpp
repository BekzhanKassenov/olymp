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
const int MAXN = 1000010;
const int LG = 21;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k;
int v[MAXN], c[MAXN];
int t1[LG][MAXN], t2[LG][MAXN];
int level[MAXN];
int z[MAXN];

int _max(int a, int b) {
    return max(a, b);
}

int _min(int a, int b) {
    return min(a, b);
}

void build(int t[LG][MAXN], int a[MAXN], int (*f)(int, int)) {
    for (int i = 0; i < n; i++) {
        t[0][i] = a[i];
    }

    for (int l = 1; l < LG; l++) {
        for (int i = 0; i < n; i++) {
            t[l][i] = t[l - 1][i];

            if (i + (1 << l) <= n) {
                t[l][i] = (*f)(t[l - 1][i], t[l - 1][i + (1 << (l - 1))]);
            }
        }
    }
}

void preprocess() {
    build(t1, v, _max);
    build(t2, c, _min);

    level[0] = 0;
    level[1] = 0;
    for (int i = 2; i <= n; i++) {
        level[i] = level[i >> 1] + 1;
    }
}

int get(int t[LG][MAXN], int l, int r, int (*f)(int, int)) {
    int lev = level[r - l + 1];

    return (*f)(t[lev][l], t[lev][r - (1 << lev) + 1]);
}

int getPotential(int start) {
    int _left = start;
    int _right = n - 1;

    int ans = max(min(v[start], c[start]), min(get(t1, start, n - 1, _max), get(t2, start, n - 1, _min)));

    while (_right - _left >= 5) {
        int mid = (_left + _right) / 2;

        int vv = get(t1, start, mid, _max);
        int cc = get(t2, start, mid, _min);

        if (vv <= cc) {
            _left = mid;
        } else {
            _right = mid;
        }
    }

    for (int i = _left; i <= _right; i++) {
        int vv = get(t1, start, i, _max);
        int cc = get(t2, start, i, _min);

        ans = max(ans, min(vv, cc));
    }
    
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        v[i] *= 100;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    preprocess();

    for (int i = 0; i < n; i++) {
        z[i] = getPotential(i);
    }

    sort(z, z + n);

    double ans = 0;
    double ratio = k / (n + .0);

    double x = n - k;
    double y = n - 1;

    for (int i = 0; i + k <= n; i++) {
        ans += z[i] * ratio;

        if (y > 0) {
            ratio *= x / y;
        }

        x--, y--;
    }

    printf("%.10lf\n", ans);

    return 0;
}
