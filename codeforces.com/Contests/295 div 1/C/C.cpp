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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int rev[MAXN];
int fact[MAXN];
int revfact[MAXN];
int sum[MAXN];
int n, k, ans;
char s[MAXN];

void build() {
    rev[1] = 1;
    fact[0] = 1;
    fact[1] = 1;
    revfact[0] = 1;
    revfact[1] = 1;
    sum[0] = s[0] - '0';
    sum[1] = sum[0] + s[1] - '0';

    for (int i = 2; i <= n; i++) {
        rev[i] = (1ll * (MOD - MOD / i) * rev[MOD % i]) % MOD;
        
        fact[i] = (1ll * i * fact[i - 1]) % MOD;
        revfact[i] = (1ll * rev[i] * revfact[i - 1]) % MOD;
        
        sum[i] = (sum[i - 1] + s[i] - '0') % MOD;
    }
}

int choose(int n, int k) {
    if (k > n) {
        return 0;
    }
    
    long long num = fact[n];
    long long revden = (1ll * revfact[k] * revfact[n - k]) % MOD;

    return (num * revden) % MOD;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d %d\n", &n, &k);

    gets(s);

    build();

    int power10 = 1;
    for (int i = n - 1; i >= 0; i--) {
        ans += ((1ll * power10 * choose(i, k)) % MOD * (s[i] - '0')) % MOD;
        ans %= MOD;
        power10 = (power10 * 10ll) % MOD;
    }

    power10 = 1;
    for (int l = 0; l <= n - 2; l++) {
        long long addend = (1ll * power10 * choose(n - l - 2, k - 1)) % MOD;
        addend *= sum[n - l - 2];
        addend %= MOD;
        
        ans += addend;
        ans %= MOD;

        power10 = (power10 * 10ll) % MOD;
    }

    printf("%d\n", ans);
    
    return 0;
}
