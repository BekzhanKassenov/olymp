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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, k;
int cnt[MAXN];
int fact[MAXN], rfact[MAXN];
int rev[MAXN];

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

void build() {
    fact[0] = 1;
    rfact[0] = 1;

    for (int i = 1; i < MAXN; i++) {
        fact[i] = (1ll * fact[i - 1] * i) % MOD;
        rev[i] = binpow(i, MOD - 2);
        rfact[i] = (1ll * rfact[i - 1] * rev[i]) % MOD;
    }
}

int C(int n, int k) {
    int result = fact[n];
    result = (1ll * result * rfact[k]) % MOD;
    result = (1ll * result * rfact[n - k]) % MOD;

    return result;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &m, &k);    

    build();

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }

    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int num = 0;
        for (int j = 1; j <= m; j++) {
            if (cnt[j] == i) {
                num += i;
            }
        }

        if (k >= num) {
            k -= num;
        } else {
            ans = C(num, k);
            break;
        }
    }

    printf("%d\n", ans);

    return 0;
}
