/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;
const int LG = 25;

int anc[MAXN][LG], ancDP[MAXN][LG];
int dp[MAXN][2];
vector <pair <int, int> > q[MAXN];
vector <int> g[MAXN];
vector <int> child[MAXN][LG];
int n, m, x, y;
int tin[MAXN], tout[MAXN], timer;

void dfs(int v, int pr = 0) {
    tin[v] = ++timer;

    anc[v][0] = pr;
    for (int i = 1; i < LG; i++) {
        anc[v][i] = anc[anc[v][i - 1]][i - 1];
    }

    for (size_t i = 0; i < g[v].size(); i++) {
        if (g[v][i] != pr)
            dfs(g[v][i], v);
    }

    tout[v] = ++timer;
}

bool ancestor(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b) {
    if (ancestor(a, b))
        return a;

    if (ancestor(b, a))
        return b;

    for (int i = LG - 1; i >= 0; i--) {
        if (!ancestor(anc[a][i], b))
            a = anc[a][i];
    }

    return anc[a][0];
}

void update(int v, int a, int b) {
    int temp = 1;

    if (a != v)
        temp += dp[a][0];

    if (b != v)
        temp += dp[b][0];

    for (int i = LG - 1; i >= 0; i--) {
        if (!ancestor(anc[a][i], v)) {
            temp += ancDP[a][i];
            a = anc[a][i];
        }

        if (!ancestor(anc[b][i], v)) {
            temp += ancDP[b][i];
            b = anc[b][i];
        }
    }

    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];

        if (!ancestor(to, a) && !ancestor(to, b))
            temp += max(dp[to][0], dp[to][1]);
    }

    dp[v][1] = max(dp[v][1], temp);
}

void dfsDP(int v) {
    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to != anc[v][0]) {
            dfsDP(to);
            dp[v][0] += max(dp[to][0], dp[to][1]);
        }
    }

    for (size_t i = 0; i < q[v].size(); i++) {
        int a = q[v][i].first;
        int b = q[v][i].second;

        update(v, a, b);
    }

    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        ancDP[to][0] = dp[v][0] - max(dp[to][0], dp[to][1]);
    }

    for (int i = 1; i < LG; i++) {
        for (size_t j = 0; j < child[v][i].size(); j++) {
            int to = child[v][i][j];

            ancDP[to][i] = ancDP[to][i - 1] + ancDP[anc[to][i - 1]][i - 1];
        }

        child[anc[v][i]][i].push_back(v);
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &x, &y);
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0);

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        x--, y--;
        int l = lca(x, y);

        q[l].push_back(make_pair(x, y));
    }

    dfsDP(0);

    printf("%d\n", max(dp[0][0], dp[0][1])); 
    
    return 0;
}
        