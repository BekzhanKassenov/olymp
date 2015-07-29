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
const int MAXN = 200010;
const int MAXK = 2010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int fact[MAXN], revfact[MAXN];

int binpow(int base, int power) {
    int result = 1;

    while (power > 0) {
        if (power & 1) {
            result = (1ll * result * base) % MOD;
        }

        base = (1ll * base * base) % MOD;
        power >>= 1;
    }

    return result;
}

void build() {
    fact[0] = 1;
    revfact[0] = 1;

    for (int i = 1; i < MAXN; i++) {
        fact[i] = (1ll * fact[i - 1] * i) % MOD;
        revfact[i] = (1ll * revfact[i - 1] * binpow(i, MOD - 2)) % MOD;
    }
}

int C(int n, int k) {
    int result = fact[n];
    result = (1ll * result * revfact[k]) % MOD;
    result = (1ll * result * revfact[n - k]) % MOD;
    return result;
}

int dp[MAXK];
pair <int, int> a[MAXK];
int h, w, n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    build();
    
    scanf("%d%d%d", &h, &w, &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }

    a[n].first = h;
    a[n].second = w;

    n++;

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        dp[i] = C(a[i].first + a[i].second - 2, a[i].first - 1);

        for (int j = 0; j < i; j++) {
            if (a[j].first > a[i].first || a[j].second > a[i].second) {
                continue;
            }

            int h = a[i].first - a[j].first + 1;
            int w = a[i].second - a[j].second + 1;

            dp[i] -= (1ll * C(h + w - 2, h - 1) * dp[j]) % MOD;
            dp[i] = ((dp[i] % MOD) + MOD) % MOD;
        }
    }

    printf("%d\n", dp[n - 1]);
    
    return 0;
}
