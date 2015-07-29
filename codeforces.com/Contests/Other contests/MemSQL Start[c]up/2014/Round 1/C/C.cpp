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

int n, m;

double C(int n, int k) {
    k = min(k, n - k);

    double res = 1;

    for (int i = k + 1; i <= n; i++)
        res *= i;

    for (int i = 2; i <= n - k; i++)
        res /= i;

    return res;
}

double solve() {
    double res = 1;

    for (int k = 1; k <= m; k++)
        res += C(m, k) * C(m * (n - 1), n - k) * sqr(k);

    res /= C(n * m, n) * n;

    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    printf("%.10lf", solve());

    return 0;
}
