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
const int MAXN = 5050;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, k;
int a[MAXN];
ll sum[MAXN], dp[MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &m, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }

    for (int kk = 1; kk <= k; kk++) {
        ll mx = 0;
        for (int i = kk * m; i <= n; i++) {
            dp[kk][i] = max(mx, dp[kk - 1][i - m] + sum[i] - sum[i - m]);
            mx = max(mx, dp[kk][i]);
        }
    }

    printf("%I64d\n", dp[k][n]);

    return 0;
}
