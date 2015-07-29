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
const int INF = 1 << 30;
const int MAXN = 1010;
const int MAXM = 10 * MAXN * MAXN;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct MaxFlow {
    int to[MAXM];
    int flow[MAXM];
    int cap[MAXM];
    int lastE;

    MaxFlow() : lastE(0) { }

    vector <int> g[MAXN];
    bool used[MAXN];

    void addEdge(int from, int to, int cap) {
        this->to[lastE] = to;
        this->flow[lastE] = 0;
        this->cap[lastE] = cap;
        g[from].push_back(lastE);
        lastE++;

        this->to[lastE] = from;
        this->flow[lastE] = 0;
        this->cap[lastE] = 0;
        g[to].push_back(lastE);
        lastE++;
    }

    bool dfs(int v, int T, int addFlow) {
        used[v] = true;

        if (v == T) {
            return true;
        }

        for (size_t i = 0; i < g[v].size(); i++) {
            int idx = g[v][i];

            if (!used[to[idx]] && cap[idx] - flow[idx] >= addFlow && dfs(to[idx], T, addFlow)) {
                flow[idx] += addFlow;
                flow[idx ^ 1] -= addFlow;
                return true;
            }
        }
        
        return false;
    }

    int getMaxFlow(int S, int T) {
        int flow = 0;
        int addFlow = INF;

        while (addFlow > 0) {
            memset(used, false, sizeof used);
            if (dfs(S, T, addFlow)) {
                flow += addFlow;
            } else {
                addFlow >>= 1;
            }
        }

        return flow;
    }
};

struct DSU {
    int par[MAXN];

    DSU(int n) {
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
    }

    int get_par(int v) {
        if (par[v] == v) {
            return v;
        }

        return par[v] = get_par(par[v]);
    }

    void unite(int a, int b) {
        a = get_par(a);
        b = get_par(b);

        if (a != b) {
            par[a] = b;
        }
    }
};

int n, m;
int x, y;
int S, T;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d", &n, &m);

    S = 0, T = 2 * n + 1;

    MaxFlow maxFlow;

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        maxFlow.addEdge(x, y + n, 1);
    }

    for (int i = 1; i <= n; i++) {
        maxFlow.addEdge(S, i, 1);
        maxFlow.addEdge(i + n, T, 1);
    }

    maxFlow.getMaxFlow(S, T);

    DSU dsu(n);
    for (int i = 1; i <= n; i++) {
        for (size_t j = 0; j < maxFlow.g[i].size(); j++) {
            int idx = maxFlow.g[i][j];

            if (maxFlow.to[idx] != S && maxFlow.flow[idx] > 0) {
                dsu.unite(i, maxFlow.to[idx] - n);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dsu.get_par(i) == i) {
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
