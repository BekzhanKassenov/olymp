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
const int MAXN = 5000 * 1000 + 10;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

bool prime[MAXN];
vector <int> primes;
int lp[MAXN], f[MAXN];
int T, a, b;

void build() {
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;
    lp[0] = lp[1] = 1;

    for (int i = 2; i < MAXN; i++) {
        if (!prime[i]) {
            continue;
        }

        primes.push_back(i);
        lp[i] = i;

        if (1ll * i * i < MAXN) {
            for (int j = i * i; j < MAXN; j += i) {
                prime[j] = false;
                lp[j] = i;
            }
        }
    }

    for (int i = 2; i < MAXN; i++) {
        f[i] = f[i / lp[i]] + 1;
    }

    for (int i = 1; i < MAXN; i++) {
        f[i] += f[i - 1];
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
   
    build();

    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &a, &b);

        printf("%d\n", f[a] - f[b]);
    }

    return 0;
}
