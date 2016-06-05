#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 20010;
const int LG = 15;

int n, q;
vector <int> g[MAXN];
int innerDP[MAXN];
int outerDP[MAXN];
int mx1[MAXN], mx2[MAXN];
int dp[MAXN];

int depth[MAXN];
int anc[LG][MAXN];
int tin[MAXN], tout[MAXN], timer;

void dfs(int v, int par = 0) {
    tin[v] = timer++;
    if (par != 0) {
        anc[0][v] = par;
    } else {
        anc[0][v] = v;
    }

    for (int i = 1; i < LG; i++) {
        anc[i][v] = anc[i - 1][anc[i - 1][v]];   
    }

    for (int to: g[v]) {
        if (to != par) {
            depth[to] = depth[v] + 1;
            dfs(to, v);
        }
    }

    tout[v] = timer++;
}

bool ancestor(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b) {
    if (ancestor(a, b)) {
        return a;   
    }

    if (ancestor(b, a)) {
        return b;
    }

    for (int i = LG - 1; i >= 0; i--) {
        if (!ancestor(anc[i][a], b)) {
            a = anc[i][a];
        }
    }

    return anc[0][a];
}

int get_nth(int from, int to, int l, int dist) {
    int dist1 = depth[from] - depth[l];
    int dist2 = depth[to] - depth[l];

    int ver = -1, cnt = -1;
    if (dist <= dist1) {
        ver = from;
        cnt = dist;
    } else {
        ver = to;
        cnt = dist1 + dist2 - dist;
    }

    if (cnt < 0) {
        return 0;
    }

    for (int i = 0; i < LG; i++) {
        if (cnt & (1 << i)) {
            ver = anc[i][ver];
        }
    }

    return ver;
}

int get_dist(int from, int to) {
    if (ancestor(from, to)) {
        return depth[to] - depth[from];
    }

    if (ancestor(to, from)) {
        return depth[from] - depth[to];
    }

    int l = lca(from, to);
    return depth[from] + depth[to] - 2 * depth[l];
}

void dfsInner(int v, int par = 0) {
    innerDP[v] = v;

    mx1[v] = -1, mx2[v] = -1;
    for (int to: g[v]) {
        if (to != par) {
            dfsInner(to, v);
            if (depth[innerDP[to]] > depth[innerDP[v]]) {
                innerDP[v] = innerDP[to];
            }

            if (mx1[v] == -1 || depth[innerDP[to]] > depth[mx1[v]]) {
                mx2[v] = mx1[v];
                mx1[v] = innerDP[to];
            } else if (mx2[v] == -1 || depth[innerDP[to]] > depth[mx2[v]]) {
                mx2[v] = innerDP[to];
            }
        }
    }
}

void dfsOuter(int v, int par = 0) {
    outerDP[v] = v;
    if (par != 0) {
        outerDP[v] = outerDP[par];
        int mx = mx1[par];

        if (mx == innerDP[v]) {
            mx = mx2[par];
        }

        if (mx != -1) {
            int dnew = get_dist(v, mx);
            int dold = get_dist(v, outerDP[v]);

            if (dnew > dold) {
                outerDP[v] = mx;
            }
        }
    }

    for (int to: g[v]) {
        if (to != par) {
            dfsOuter(to, v);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &q);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    dfsInner(1);
    dfsOuter(1);
    
    for (int i = 1; i <= n; i++) {
        int dInner = get_dist(i, innerDP[i]);
        int dOuter = get_dist(i, outerDP[i]);

        dp[i] = innerDP[i];
        if (dOuter > dInner) {
            dp[i] = outerDP[i];
        }
    }

    while (q--) {
        int v, d;
        scanf("%d%d", &v, &d);

        int l = lca(v, dp[v]);
        printf("%d\n", get_nth(v, dp[v], l, d));
    }

    return 0;
}
