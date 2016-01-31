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
typedef vector <vector <int> > matr;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 50010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int b;
int k, x;
int a[MAXN];

matr operator * (const matr& a, const matr& b) {
    matr c(x, vector <int>(x));

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            c[i][j] = 0;
            for (int k = 0; k < x; k++) {
                c[i][j] += (1ll * a[i][k] * b[k][j]) % MOD;
                c[i][j] %= MOD;
            }
        }
    }

    return c;
}

matr binpow(matr a, int p) {
    matr result(x, vector <int> (x));

    for (int i = 0; i < x; i++) {
        result[i][i] = 1;
    }

    while (p > 0) {
        if (p & 1) {
            result = result * a;
        }

        a = a * a;
        p >>= 1;
    }

    return result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d%d", &n, &b, &k, &x);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    matr m(x, vector <int> (x));
    for (int rem = 0; rem < x; rem++) {
        for (int i = 0; i < n; i++) {
            int to = (rem * 10 + a[i]) % x;

            m[to][rem]++;
        }
    }

    m = binpow(m, b);

    /*
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            cerr << m[i][j] << ' ';
        }
        cerr << endl;
    }
    */

    printf("%d\n", m[k][0]);

    return 0;
}
