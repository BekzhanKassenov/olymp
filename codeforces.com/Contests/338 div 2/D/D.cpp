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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int binpow(int base, int p) {
    int ans = 1;

    while (p > 0) {
        if (p & 1) {
            ans = (1ll * ans * base) % MOD;
        }

        base = (1ll * base * base) % MOD;
        p >>= 1;
    }

    return ans;
}

int n;
int cnt[MAXN];
int l[MAXN], r[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }

    l[0] = cnt[0] + 1;

    for (int i = 1; i < MAXN; i++) {
        l[i] = (1ll * l[i - 1] * (cnt[i] + 1)) % (MOD - 1);
    }

    r[MAXN - 1] = cnt[MAXN - 1] + 1;
    for (int i = MAXN - 2; i >= 0; i--) {
        r[i] = (1ll * r[i + 1] * (cnt[i] + 1)) % (MOD - 1);
    }

    int ans = 1;
    for (int i = 1; i < MAXN - 1; i++) {
        if (cnt[i] == 0) {
            continue;
        }

        int p = (1ll * l[i - 1] * r[i + 1]) % (MOD - 1);

        int pr = 1;
        for (int j = 0; j < cnt[i]; j++) {
            pr = (1ll * pr * i) % MOD;
            ans = (1ll * ans * binpow(pr, p)) % MOD;
        }
    }

    printf("%d\n", ans);

    return 0;
}
