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
const ll lim = (long long)1e13;
const ll MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

ll sum[1 << 24];
ll dp[1 << 24];
int n, m;
int a[24], b[2];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    sum[0] = 0;
    sort(b, b + m);

    dp[0] = 1;
    sum[0] = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        int pos = __builtin_ctz(mask);
        sum[mask] = sum[mask ^ (1 << pos)] + a[pos];
        
        bool flag = false;
        for (int i = 0; i < m && !flag; i++) {
            if (sum[mask] == b[i])
                flag = true;
        }

        if (flag)
            continue;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                dp[mask] += dp[mask ^ (1 << i)];
                if (dp[mask] > lim)
                    dp[mask] %= MOD;
            }
        }

        dp[mask] %= MOD;
    }

    printf("%I64d\n", dp[(1 << n) - 1]);

    return 0;
}
