/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

#ifdef _WIN32
# define I64 "%I64d"
#else
# define I64 "%lld"
#endif

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

bool isPrime[MAXN];
vector <int> primes;
int n;
long long a[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf(I64, &a[i]);
        a[i] += a[i - 1];
    }

    memset(isPrime, true, sizeof isPrime);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);

            if (1ll * i * i < n) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    long long ans = 0;
    for (int prime: primes) {
        ans += (a[n] - a[prime]) - a[n - prime];
    }

    printf(I64, ans);
    
    return 0;
}
