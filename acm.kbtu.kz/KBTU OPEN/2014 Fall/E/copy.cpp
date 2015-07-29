/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "growingtree"

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

int n, k;
long long T;

void mul(long long a[3][3], long long b[3][3], long long c[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            c[i][j] = 0;

            for (int k = 0; k < 3; k++) {
                c[i][j] += (a[i][k] * b[k][j]) % MOD;
                c[i][j] %= MOD;
            }
        }
    }
}

void cpy(long long dest[3][3], long long source[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            dest[i][j] = source[i][j];
}

void binpow(long long a[3][3], long long p) {
    long long result[3][3] = {{k, 0, 0},
                              {n, 1, (-1 + MOD)},
                              {k, 0, 0}};
    
    long long temp[3][3];

    while (p) {
        if (p & 1) {
            mul(result, a, temp);
            cpy(result, temp);
        }

        mul(a, a, temp);
        cpy(a, temp);

        p >>= 1;
    }

    cpy(a, result);
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d%d%I64d", &n, &k, &T);

    long long a[3][3] = {{k, 0, 0}, 
                         {n, 1, (-1 + MOD)}, 
                         {k, 0, 0}};

    binpow(a, T);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%11I64d", a[i][j]);
        }
        puts("");
    }

    printf("%I64d\n", a[1][0]);

    return 0;
}
