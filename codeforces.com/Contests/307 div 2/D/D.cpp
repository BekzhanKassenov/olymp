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
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

long long MOD;
long long n, k, l;

struct Matrix {
    int a, b, c, d;

    Matrix() : a(1), b(0), c(0), d(1) { }
};                      

Matrix operator * (const Matrix& lhs, const Matrix& rhs) {
    Matrix result;

    result.a = (1ll * lhs.a * rhs.a + 1ll * lhs.b * rhs.c) % MOD;
    result.b = (1ll * lhs.a * rhs.b + 1ll * lhs.b * rhs.d) % MOD;

    result.c = (1ll * lhs.c * rhs.a + 1ll * lhs.d * rhs.c) % MOD;
    result.d = (1ll * lhs.c * rhs.b + 1ll * lhs.d * rhs.d) % MOD;

    return result;
}

Matrix binpow(Matrix mat, long long p) {
    Matrix result;

    while (p) {
        if (p & 1) {
            result = result * mat;
        }

        mat = mat * mat;
        p >>= 1;
    }

    return result;
}

int fib(long long n) {
    Matrix mat;
    mat.a = 1;
    mat.b = 1;
    mat.c = 1;
    mat.d = 0;

    mat = binpow(mat, n + 1);
    return mat.a;
}

long long binpow(long long n, long long p) {
    long long result = 1;

    while (p) {
        if (p & 1) {
            result = (result * n) % MOD;
        }

        n = (n * n) % MOD;
        p >>= 1;
    }

    return result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    cin >> n >> k >> l >> MOD;

    long long cnt0 = fib(n);
    long long cnt1 = ((binpow(2, n) - cnt0) % MOD + MOD) % MOD;
    long long result = 1 % MOD;

    for (int i = 0; i < l; i++) {
        if (k & 1ll) {
            result = (result * cnt1) % MOD;
        } else {
            result = (result * cnt0) % MOD;
        }

        k >>= 1;
    }

    if (k > 0) {
        result = 0;
    }

    cout << result << endl;
    
    return 0;
}
