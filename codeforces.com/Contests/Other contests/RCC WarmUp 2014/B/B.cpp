/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2000 * 1000 * 1000 * 1ll * 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 110;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

struct item {
    int x, k, mask;

    void read() {
        int size, xx;
        scanf("%d%d%d", &x, &k, &size);

        mask = 0;

        for (int i = 0; i < size; i++) {
            scanf("%d", &xx);
            mask |= (1 << (xx - 1));
        }
    }
    
    bool operator < (const item& it) const {
        return k < it.k;
    }
};

int n, m;
item a[maxn];
ll dp[1 << 20], res = INF, b;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d%I64d", &n, &m, &b);
    
    for (int i = 0; i < n; i++) {
        a[i].read();
    }

    sort(a, a + n);
    
    for (int i = 1; i < (1 << m); i++) {
        dp[i] = INF;
    }

    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << m); mask++) {
            dp[mask | a[i].mask] = min(dp[mask | a[i].mask], dp[mask] + a[i].x);
        }

        if (dp[(1 << m) - 1] != INF)
            res = min(res, dp[(1 << m) - 1] + a[i].k * b);
    }

    if (res == INF)
        puts("-1");
    else
        printf("%I64d", res);

    return 0;
}
