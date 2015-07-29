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
const int INF = 2000 * 1000 * 1000 + 1000;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int x[MAXN], h[MAXN];
int dp[MAXN][3], ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &x[i], &h[i]);
    }

    x[0] = -INF;
    h[0] = 0;

    x[n + 1] = INF;
    h[n + 1] = 0;

    for (int i = 1; i <= n; i++) {
        int maxprev = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);

        dp[i][0] = maxprev;

        if (x[i] + h[i] < x[i + 1]) {
            dp[i][1] = maxprev + 1;
        }
        
        if (x[i] - h[i] > x[i - 1] + h[i - 1]) {
            dp[i][2] = maxprev + 1;
        } else if (x[i] - h[i] > x[i - 1]) {
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
        }

        ans = max(ans, max(dp[i][0], max(dp[i][1], dp[i][2])));
    }

    printf("%d\n", ans);
    return 0;
}
