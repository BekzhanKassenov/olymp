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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
vector <int> g[MAXN];
int color[MAXN];

bool dfs(int v, int par = 0) {
    color[v] = 1;

    bool hasCycle = false;
    for (int to: g[v]) {
        if (to == par) {
            continue;
        }

        if (color[to] == 1) {
            hasCycle = true;
        } else if (color[to] == 0) {
            hasCycle |= dfs(to, v);
        }
    }

    return hasCycle;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            ans += !dfs(i);
        }
    }

    printf("%d\n", ans);

    return 0;
}
