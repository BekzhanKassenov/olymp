/****************************************
**          Solution by NU #2          **
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

double x, y, r;
int n;

void mul(double a[2][2], double b[2][2], double c[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            a[i][j] = 0;

            for (int k = 0; k < 2; k++) {
                a[i][j] += b[i][k] * c[k][j];
            }
        }
    }
}

void binpow(double a[2][2], int st) {
    double res[2][2] = {{1.0, 0.0}, {0.0, 1.0}};
    double temp[2][2];

    while (st) {
        if (st & 1) {
            mul(temp, res, a);
            memcpy(res, temp, sizeof(double) * 4);
        }

        mul(temp, a, a);
        memcpy(a, temp, sizeof(double) * 4);
        st >>= 1;
    }

    memcpy(a, res, sizeof(double) * 4);
}
                                                 
int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    while (scanf("%lf%lf%d%lf", &x, &y, &n, &r) && (x != 0 || y != 0 || n || r != 0)) {
        double a[2][2] = {{r / 1200.0 + 1.0, -y}, {0, 1}};
        binpow(a, n * 12);

        double res = a[0][0] * x + a[0][1];

        if (res <= 0.0)
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}
