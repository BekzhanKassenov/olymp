#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

const int MAXN = 110;

struct edge {
    int to, cost;

    edge() { }

    edge(int to, int cost) : to(to), cost(cost) { }
};

vector <int> g[MAXN];
edge e[2 * MAXN];
int n, k, a, b, c;
int dp[MAXN][MAXN];
bool calced[MAXN][MAXN];
int size[MAXN], cost[MAXN];

void dfs(int v, int pr = 0) {
    size[v] = 1;
    cost[v] = 0;

    for (size_t i = 0; i < g[v].size(); i++) {
        int to = e[g[v][i]].to;

        if (to == pr)
            continue;

        dfs(to, v);
        size[v] += size[to];
        cost[v] += cost[to];
        cost[v] += e[g[v][i]].cost;
    }
}

void dfsDP(int v, int cnt, int pr = 0) {
    if (calced[v][cnt])
        return;

    calced[v][cnt] = true;
    
    if (cnt >= size[v] - 1 || g[v].empty()) {
        cout << "v: " << v << "  cnt: " << cnt << "  size[v]: " << size[v] << " DP: 0" << endl;
        return;
    }

    int a = -1, b = -1;
    int ca = -1, cb = -1;

    for (size_t i = 0; i < g[v].size(); i++) {
        int to = e[g[v][i]].to;
        
        if (to != pr) {
            if (a == -1) {
                ca = e[g[v][i]].cost;
                a = to;
            } else {
                cb = e[g[v][i]].cost;
                b = to;
            }
        }
    }

    assert(a != -1 && b != -1 && ca != -1 && cb != -1);

    dfsDP(a, cnt - size[b], v);
    dfsDP(b, cnt - size[a], v);

    dp[v][cnt] = max(dp[a][cnt - size[b]] + ca, dp[b][cnt - size[a]] + cb);

    for (int i = 1; i < cnt; i++) {    
        if (i == size[a] || cnt - i == size[b])
            continue;

        dfsDP(a, i, v);
        dfsDP(b, cnt - i, v);
        
        dp[v][cnt] = max(dp[v][cnt], dp[a][i] + dp[b][cnt - i] + ca + cb);
    }

    cout << "v: " << v << "  cnt: " << cnt << "  size[v]: " << size[v] << " DP: " << dp[v][cnt] << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d%d", &a, &b, &c);
        
        e[2 * i] = edge(b, c);
        g[a].push_back(2 * i);

        e[2 * i + 1] = edge(a, c);
        g[b].push_back(2 * i + 1);
    }

    dfs(1);

    dfsDP(1, n - k);

//    for (int i = 1; i <= n; i++)
//        cout << size[i] << ' ' << cost[i] << endl;

    printf("%d", dp[1][n - k]);

    return 0;
}