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

int n;

int binpow(int n, int p, int MOD) {
    int res = 1;

    while (p > 0) {
        if (p & 1) {
            res = (1ll * res * n) % MOD;
        }

        n = (1ll * n * n) % MOD;
        p >>= 1;
    }

    return res;
}

int fact(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res = (1ll * res * i) % MOD;
    }
    
    return res;
}

int rev(int n) {
    return binpow(n, MOD - 2, MOD);
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    int result = fact(2 * n);
    result = (1ll * result * rev(fact(n))) % MOD; 
    result = (1ll * result * rev(fact(n))) % MOD;

    result = (1ll * result * rev(n + 1)) % MOD;

    printf("%d\n", result);

    return 0;
}
