#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct Num {
    static long long mod;
    long long n;

    Num(long long k = 0) {
        n = k % mod;
    }

    Num& operator += (const Num& k) { n += k.n; n %= mod; return *this; }

    Num& operator *= (Num k) {
        Num res = 0;

        for (long long p = n; p > 0; p >>= 1) {
            if (p & 1) {
                res += k;
            }

            k += k;
        }

        return *this = res;
    }
};

#define defop1(x, y) Num operator x (Num a, const Num& k) { return a y k; }
defop1(+, +=);
defop1(*, *=);

long long Num::mod = 0;

void muleq(Num a[2][2], Num b[2][2]) {
    Num c[2][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            a[i][j] = c[i][j];
        }
    }
}

void binpow(Num a[2][2], long long p) {
    Num res[2][2] = {
        { Num(1), Num(0) },
        { Num(0), Num(1) }
    };

    for (; p > 0; p >>= 1) {
        if (p & 1) {
            muleq(res, a);
        }

        muleq(a, a);
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            a[i][j] = res[i][j];
        }
    }
}

long long n, k, m;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n >> k >> m;

    Num::mod = m;

    Num a[2][2] = {
         { Num(k - 1), Num(k - 1) },
         { Num(1), Num(0) }
    };
    
    binpow(a, n - 1);

    cout << (a[0][0] * Num(k - 1) + a[1][0] * Num(k - 1)).n << endl;

    return 0;
}
