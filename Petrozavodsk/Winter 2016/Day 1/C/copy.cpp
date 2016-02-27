/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#ifdef Local
# define I64 "%I64d"
#else
# define I64 "%Ld"
#endif

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int INF = 2000 * 1000 * 1000;
const int MAXN = 5010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

long long mul(long long a, long long b, long long MOD) {
    long long result = 0;
    while (b > 0) {
        if (b & 1) {
            result = (result + a) % MOD;
        }

        a = (a + a) % MOD;
        b >>= 1;
    }

    return result;
}

long long gcdex(long long a, long long b, long long& x, long long& y, long long M) {
    if (a == 0) {
        x = 0, y = 1;
        return b;
    }

    long long xx, yy;
    long long g = gcdex(b % a, a, xx, yy, M);
    x = yy - mul(b / a, xx, M);
    x %= M;
    x += M;
    x %= M;

    y = xx;

    return g;
}

long long gcd(long long a, long long b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }

    return a + b;
}

long long getPrime(long long M) {
    long long x = 2, y = 2;

    for (int i = 0; i < 100000; i++) {
        x = f(x, M);
        y = f(f(y, M), M);

        long long val = y - x;
        val = ((val % M) + M) % M;

        long long g = gcd(val, M);

        if (g != 1) {
            return g;
        }
    }

    return M;
}

int n, m, q;
long long a[MAXN], b[MAXN];
long long aa[MAXN], bb[MAXN];
long long M;

bool invert(long long x, long long M, long long& res) {
    long long xx, yy;
    long long g = gcdex(x, M, xx, yy, M);

    if (g != 1) {
        return false;
    }

    res = xx;
    return true;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf(I64, &a[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf(I64, &b[i]);
    }

    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            long long g = gcd(a[i], b[j]);
            a[i] /= g;
            b[j] /= g;
        }
    }
    */

    scanf("%d", &q);

    for (int qq = 0; qq < q; qq++) {
        scanf(I64, &M);

        long long result = 1;
        for (int i = 0; i < n; i++) {
            result = mul(result, a[i], M);
        }

        bool ok = true;
        for (int j = 0; j < m && ok; j++) {
            long long inv;
            ok &= invert(b[j], M, inv);
            result = mul(result, inv, M);
        }

        if (ok) {
            printf(I64 "\n", result);
        } else {
            puts("DIVISION BY ZERO");
        }
    }
    
    return 0;
}
