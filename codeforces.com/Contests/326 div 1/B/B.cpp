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
const int MAXN = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k;
long long l;
int a[MAXN], b[MAXN];
map <int, int> pos;
vector <vector <int> > dp;

int binpow(int base, int p) {
    int result = 1;

    while (p > 0) {
        if (p & 1) {
            result = (1ll * result * base) % MOD;
        }

        base = (1ll * base * base) % MOD;
        p >>= 1;
    }

    return result;
}

int fact(int n) {
    if (n == 0) {
        return 1;
    }

    return (1ll * n * fact(n - 1)) % MOD;
}

int rfact(int n) {
    return binpow(fact(n), MOD - 2);
}

int C(int n, int k) {
    if (n < k) {
        return 0;
    }

    int result = fact(n);
    result = (1ll * result * rfact(k)) % MOD;
    result = (1ll * result * rfact(n - k)) % MOD;

    return result;
}

int solve(int k) {
    int ans = dp[k][n - 1];
    ans = (1ll * ans * C(l / n, k)) % MOD;

    for (int i = 0; i < l % n; i++) {
        ans += (1ll * dp[k - 1][pos[a[i]]] * C(l / n, k - 1)) % MOD;
        ans %= MOD;
    }

    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%I64d%d", &n, &l, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    sort(b, b + n);
    for (int i = 0; i < n; i++) {
        pos[b[i]] = i;
    }

    dp.resize(k + 1);
    for (int i = 0; i <= k; i++) {
        dp[i].resize(n);
    }

    for (int i = 0; i < n; i++) {
        dp[1][i] = i + 1;
    }

    for (int i = 2; i <= k; i++) {
        dp[i][0] = dp[i - 1][pos[b[0]]];

        for (int j = 1; j < n; j++) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][pos[b[j]]]) % MOD;
        }
    }

    int ans = l % MOD;
    for (int i = 2; i <= k; i++) {
        ans = (ans + solve(i)) % MOD;
    }

    printf("%d\n", ans);

    return 0;
}
