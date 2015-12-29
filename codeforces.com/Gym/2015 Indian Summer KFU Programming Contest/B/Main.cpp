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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k, d;
int dp[MAXN][MAXN];
int sum[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &k, &d);

    for (int i = 1; i <= n; i++) {
        dp[1][i] = 1;
        sum[i] = sum[i - 1] + dp[1][i];
    }

    for (int i = 2; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            int l = max(1, j - d);
            int r = max(l - 1, j - 1);
            dp[i][j] = (sum[r] - sum[l - 1] + MOD) % MOD;
        }

        sum[0] = 0;
        for (int j = 1; j <= n; j++) {
            sum[j] = sum[j - 1] + dp[i][j];
            sum[j] %= MOD;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[k][i];
        ans %= MOD;
    }

    printf("%d\n", ans);
    
    return 0;
}
