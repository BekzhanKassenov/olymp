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
const int MAXN = 50100;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, a, b;
int dp[MAXN][2];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &a, &b);

    dp[0][0] = dp[0][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = max(i - a, 0); j < i; j++) {
            dp[i][0] += dp[j][1];
            dp[i][0] %= MOD;
        }

        for (int j = max(i - b, 0); j < i; j++) {
            dp[i][1] += dp[j][0];
            dp[i][1] %= MOD;
        }
    }

    printf("%d\n", (dp[n][0] + dp[n][1]) % MOD);

    return 0;
}
