/****************************************
**      Solution by NU: Black Kex      **
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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, T;
double c;
double a[MAXN];
double mean[MAXN], approx[MAXN];
double cur;
int m, q;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d %d %lf", &n, &T, &c);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &a[i]);
        if (i < T) {
            cur += a[i];
        }

        approx[i] = (approx[i - 1] + a[i] / T) / c;
    }

    for (int i = T; i <= n; i++) {
        cur += a[i];
        cur -= a[i - T];

        mean[i] = cur / T;
    }

    scanf("%d", &m);

    while (m --> 0) {
        scanf("%d", &q);

        double error = abs(mean[q] - approx[q]) / mean[q];

        printf("%.6f %.6f %.6f\n", mean[q], approx[q], error);
    }

    return 0;
}
