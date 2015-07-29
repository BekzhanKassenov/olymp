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
const int MAXN = 2010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, d, x, y, ans;
int a[MAXN];
vector <int> g[MAXN];
int dp[MAXN];
bool used[MAXN];

void dfs(int v, int idx, int pr = -1) {
    dp[v] = 1;

    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];

        if (a[to] > a[idx] || to == pr)
            continue;

        if ((a[to] == a[idx] && to > idx) || (a[to] < a[idx] && a[idx] - a[to] <= d)) { 
            dfs(to, idx, v);
            dp[v] = (dp[to] + 1) * 1ll * dp[v] % MOD;
        }

        //cout << to << ' ' << dp[to] + 1 << endl;
    }

    //cout << v << ' ' << dp[v] << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &d, &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    for (int i = 1; i <= n; i++) {
        dfs(i, i);
        ans += dp[i];
        ans %= MOD;
    }

    printf("%d\n", ans);
    
    return 0;
}
