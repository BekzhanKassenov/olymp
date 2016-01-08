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
const int MAXN = 100100;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
vector <int> g[MAXN];
int len[MAXN];
bool used[MAXN];
int deg[MAXN];

void dfs(int v) {
    used[v] = true;
    len[v] = 1;
    for (int to: g[v]) {
        if (!used[to]) {
            dfs(to);
        }
        
        len[v] = max(len[v], len[to] + 1);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);

        g[max(x, y)].push_back(min(x, y));

        deg[x]++, deg[y]++;
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i);
        }

        ans = max(ans, 1ll * len[i] * deg[i]);
    }

    printf("%lld\n", ans);

    return 0;
}
