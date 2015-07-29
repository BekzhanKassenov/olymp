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

double ans;
int n, m;

double power(double a, int n) {
    double res = 1;

    //cout << a << ' ' << n << endl;

    while (n) {
        if (n & 1)
            res *= a;

        a *= a;
        n >>= 1;
    }

    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &m, &n);

    for (int i = 0; i <= m - 1; i++) {
        ans += (power((i + 1.0) / m, n) - power((i + .0) / m, n)) * (i + 1);
    }

    printf("%.14lf\n", ans);

    return 0;
}
