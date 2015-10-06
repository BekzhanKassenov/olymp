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
const int LIM = 10000000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

bool prime[LIM];
vector <int> primes;

void sieve() {
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;

    for (int i = 2; i < LIM; i++) {
        if (prime[i]) {
            primes.push_back(i);

            if (1ll * i * i < LIM) {
                for (size_t j = i * i; j < LIM; j += i) {
                    prime[j] = false;
                }
            }
        }
    }
}

bool isPrime(int n) {
    if (n < LIM) {
        return prime[n];
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

pair <int, int> solve2(int n) {
    for (size_t i = 0; i < primes.size() && primes[i] <= n; i++) {
        if (prime[n - primes[i]]) {
            return make_pair(primes[i], n - primes[i]);
        }
    }

    return make_pair(-1, -1);
}

int n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    sieve();

    scanf("%d", &n);

    if (isPrime(n)) {
        printf("1\n%d\n", n);
        return 0;
    }

    for (int i = n - 2; i >= 0; i--) {
        if (isPrime(i)) {
            if (isPrime(n - i)) {
                printf("2\n%d %d\n", i, n - i);
                return 0;
            }

            pair <int, int> a = solve2(n - i);

            if (a != make_pair(-1, -1)) {
                printf("3\n%d %d %d\n", i, a.first, a.second);
                return 0;
            }
        }
    }

    return 0;
}
