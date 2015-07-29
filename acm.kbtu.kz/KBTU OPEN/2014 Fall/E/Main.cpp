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
const long long MOD = 100000007;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

long long binpow(long long a, long long p, long long mod) {
    long long res = 1;

    while (p) {
        if (p & 1ll)
            res = (res * a) % mod;

        a = (a * a) % mod;
        p >>= 1;
    }

    return res;
}

long long get_sol(int n, int k, long long T) {
    if (T == 0)
        return n;

    if (k == 1) {
        long long twoT = binpow(2, T, MOD);
        long long res = (twoT * (n - 1) + 1) % MOD;
        return res;
    }
    
    long long power = binpow(2ll, T, MOD - 1);

    long long bT = binpow(k, power, MOD);

    bT = (bT - 1ll + MOD) % MOD;

    long long rev = (k - 1ll + MOD) % MOD;

    rev = binpow(rev, MOD - 2ll, MOD);

    long long res = (bT * rev) % MOD;
    
    res = ((n - 1ll) * res + 1ll) % MOD;

    return res;
}

void f(long long& n, long long& k) {
    n = n * k - k + n;
    n = (n + MOD) % MOD;

    k = (k * k) % MOD;
}

long long get_stup(int n, int k, long long T) {
    long long a = n, b = k;    

    for (long long i = 0; i < T; i++) {
        f(a, b);
    }

    return a;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    int n, k;
    long long T;
    
    cin >> n >> k >> T;

    /*for (n = 3; n < 100000; n++) {
        for (k = 1; k < n; k++) {
            for (T = (ll)1e18; T <= ll(1e18); T++) {
                 long long res = get_sol(n, k, T);
                 //long long res1 = get_stup(n, k, T);

                 assert(res >= 0);

                 if (res != res1) {
                     fprintf(stderr, "%d %d %I64d\n", n, k, T);
                     fprintf(stderr, "%I64d %I64d\n", res, res1);
                     exit(0);
                 }
            }
        }
    }*/

    cout << get_sol(n, k, T) << endl;

    return 0;
}
