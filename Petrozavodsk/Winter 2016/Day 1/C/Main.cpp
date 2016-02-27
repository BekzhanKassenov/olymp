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
const int N = 1000 * 1000 * 10;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

long long mul(long long a, long long b, long long MOD) {
#ifdef Local
    long long result = 0;
    while (b > 0) {
        if (b & 1) {
            result = (result + a) % MOD;
        }

        a = (a + a) % MOD;
        b >>= 1;
    }

#else
    __int128 result = a;
    result *= b;
    result %= MOD;
#endif

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


int n, m, q;
long long a[MAXN], b[MAXN];
long long aa[MAXN], bb[MAXN];
long long M;
bool prime[N];
vector <long long> primes;

long long getPrime(long long M) {
    long long R = sqrt(M);
    if (R * R == M) {
        return R;
    }

    for (int i = 0; i < n; i++) {
        long long g = gcd(a[i], M);
        if (g != 1 && g != M
        ) {
            return g;
        }
    }

    for (int i = 0; i < m; i++) {
        long long g = gcd(b[i], M);
        if (g != 1 && g != M) {
            return g;
        }
    }

    return M;
}
void sieve() {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;

    for (long long i = 2; i < N; i++) {
        if (prime[i]) {
            primes.push_back(i);

            for (long long j = i * i; j < N; j += i) {
                prime[j] = false;
            }
        }
    }
}

bool invert(long long x, long long M, long long& res) {
    long long xx, yy;
    long long g = gcdex(x, M, xx, yy, M);

    if (g != 1) {
        return false;
    }

    res = xx;
    return true;
}

void factorize(long long N, vector <long long>& divs) {
    for (long long d: primes) {
        while (N % d == 0) {
            N /= d;
            divs.push_back(d);
        }
    }

    if (N > 1) {
        long long p = getPrime(N);
        divs.push_back(p);
        if (N / p > 1) {
            divs.push_back(N / p);
        }
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    sieve();
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf(I64, &a[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf(I64, &b[i]);
    }

    scanf("%d", &q);

    for (int qq = 0; qq < q; qq++) {
        scanf(I64, &M);
        vector <long long> divs;
        factorize(M, divs);

        multiset <long long> den;
        for (int i = 0; i < m; i++) {
            bb[i] = b[i];
            for (long long d: divs) {
                while (bb[i] % d == 0) {
                    den.insert(d);
                    bb[i] /= d;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            aa[i] = a[i];
            for (long long d: divs) {
                while (aa[i] % d == 0 && den.find(d) != den.end()) {
                    den.erase(den.find(d));
                    aa[i] /= d;
                }
            }
        }

        if (!den.empty()) {
            puts("DIVISION BY ZERO");
        } else {
            long long result = 1;
            for (int i = 0; i < n; i++) {
                result = mul(result, aa[i], M);
            }

            for (int j = 0; j < m; j++) {
                long long inv;
                invert(bb[j], M, inv);
                result = mul(result, inv, M);
            }

            printf(I64 "\n", result);
        }
    }
    
    return 0;
}
