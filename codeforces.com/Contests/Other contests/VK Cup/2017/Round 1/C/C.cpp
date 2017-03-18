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

int n, k;
vector <int> g[MAXN];
long long sum[MAXN][7];
long long dp[MAXN];
long long size[MAXN][7];

void dfs(int v, int par = -1) {
    size[v][0] = 1;
    for (int to : g[v]) {
        if (to != par) {
            dfs(to, v);

            for (int mod = 1; mod <= k; mod++) {
                size[v][mod % k] += size[to][mod - 1];
                sum[v][mod % k] += sum[to][mod - 1];
            }

            sum[v][0] += size[to][k - 1];
        }
    }

    for (int m2 = 0; m2 < k; m2++) {
        long long summ2 = 0, sizem2 = 0;

        for (int to : g[v]) {
            if (to != par) {
                summ2 += sum[to][m2];
                sizem2 += size[to][m2];
            }
        }

        for (int m1 = 0; m1 < k; m1++) {
            for (int to : g[v]) {
                if (to != par) {
                    long long osize = sizem2 - size[to][m2];
                    long long isize = size[to][m1];
                    dp[v] += sum[to][m1] * osize + (summ2 - sum[to][m2]) * isize;
                    dp[v] += isize * osize * ((m1 + m2 + 2 + k - 1) / k);
                }
            }
        }
    }

    for (int m = 0; m < k; m++) {
        dp[v] += 2 * (sum[v][m] + size[v][m] * (m != 0));
    }

    for (int to : g[v]) {
        if (to != par) {
            dp[v] += dp[to];
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    printf("%lld\n", dp[1] / 2);

    return 0;
}