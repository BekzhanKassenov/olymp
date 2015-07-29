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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int precalc[1 << 16][MAXN];
int minprec[1 << 16];
int dp[1 << 16];
int cost[MAXN][17];
int dist[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &dist[i]);

        for (int j = 0; j < m; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
        precalc[0][i] = dist[i];

    for (int mask = 1; mask < (1 << m); mask++) {
        minprec[mask] = INF;
        for (int i = 0; i < n; i++) {
            int pos = __builtin_ctz(mask);
            int prevmask = mask ^ (1 << pos);

            precalc[mask][i] = precalc[prevmask][i] + cost[i][pos];
            minprec[mask] = min(minprec[mask], precalc[mask][i]);
        }
    }

    for (int mask = 1; mask < (1 << m); mask++) {
        dp[mask] = minprec[mask];

        for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
            dp[mask] = min(dp[mask], minprec[submask] + dp[mask ^ submask]);
        }
    }

    printf("%d\n", dp[(1 << m) - 1]);
    
    return 0;
}
