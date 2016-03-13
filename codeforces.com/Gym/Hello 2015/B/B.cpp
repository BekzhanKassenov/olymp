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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

long long normalize(long long n) {
    n %= MOD;

    if (n < 0) {
        n += MOD;
        n %= MOD;
    }

    return n;
}

void add(long long& n, long long addend) {
    n += addend;

    if (n >= MOD) {
        n -= MOD;
    }
}

struct Matrix {
    long long a[2][2];

    Matrix(long long aa = 0, long long bb = 0, long long cc = 0, long long dd = 0) {
        a[0][0] = aa;
        a[0][1] = bb;
        a[1][0] = cc;
        a[1][1] = dd;
    }

    Matrix& operator += (const Matrix& m) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                add(a[i][j], m.a[i][j]);
            }
        }

        return *this;
    }

    Matrix& operator -= (const Matrix& m) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                a[i][j] = normalize(a[i][j] - m.a[i][j]);
            }
        }

        return *this;
    }

    long long get(long long f1, long long f2) const {
        return (a[0][0] * f2 + a[1][0] * f1) % MOD;
    }
};

Matrix operator * (const Matrix& a, const Matrix& b) {
    Matrix c(0, 0, 0, 0);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                add(c.a[i][j], (a.a[i][k] * b.a[k][j]) % MOD);
            }
        }
    }

    return c;
}

int n, q;
long long f1, f2, a, b;
long long x[MAXN];
Matrix f[MAXN];
Matrix query[MAXN];

void process(int l, int r) {
    add(x[l], f1);
    l++;

    if (l <= r) {
        add(x[l], f2);
        l++;

        if (l <= r) {
            query[l] += f[1];
            query[r + 1] -= f[r - l + 2];
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &q);
    scanf("%lld%lld", &f1, &f2);
    scanf("%lld%lld", &a, &b);

    Matrix mul(b, 1, a, 0);

    f[1] = mul;
    for (int i = 2; i <= n + 1; i++) {
        f[i] = f[i - 1] * mul;
    }

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &x[i]);
    }

    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        process(l, r);
    }

    Matrix cur(0, 0, 0, 0);
    for (int i = 1; i <= n; i++) {
        cur = cur * mul;
        cur += query[i];

        long long val = cur.get(f1, f2);
        add(x[i], val);
    }

    for (int i = 1; i <= n; i++) {
        printf("%lld%c", x[i], " \n"[i == n]);
    }

    return 0;
}
