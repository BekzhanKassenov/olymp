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
const int MAXM = 2 * MAXN;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Graph {
    int N;
    vector <int> g[MAXN];

    int from[2 * MAXM], to[2 * MAXM], cost[2 * MAXM];
    bool bridge[2 * MAXM];
    int lastEdge;

    bool used[MAXN];
    int tin[MAXN], fup[MAXN], timer;
    int block[MAXN];

    void setN(int N) {
        this->N = N;

        for (int i = 0; i <= N; i++) {
            g[i].clear();
        }

        timer = 0;
        lastEdge = 0;
        memset(used, false, sizeof(bool) * (N + 1));
        memset(block, 255, sizeof(int) * (N + 1));
    }

    void addEdge(int x, int y, int c) {
        from[lastEdge] = x;
        to[lastEdge] = y;
        cost[lastEdge] = c;
        bridge[lastEdge] = false;

        g[x].push_back(lastEdge);
        g[y].push_back(lastEdge);
        lastEdge++;
    }

    int getTo(int f, int idx) {
        if (from[idx] == f) {
            return to[idx];
        }

        return from[idx];
    }

    void dfsBridge(int v = 1, int par = -1) {
        used[v] = true;
        tin[v] = fup[v] = ++timer;

        for (size_t i = 0; i < g[v].size(); ++i) {
            int _to = getTo(v, g[v][i]);
            if (_to == par) {
                continue;
            }

            if (!used[_to]) {
                dfsBridge(_to, v);
                fup[v] = min(fup[v], fup[_to]);

                if (tin[v] < fup[_to]) {
                    bridge[g[v][i]] = true;
                }
            } else {
                fup[v] = min(fup[v], tin[_to]);
            }
        }
    }

    void dfsBlock(int v, int bnum) {
        block[v] = bnum;

        for (size_t i = 0; i < g[v].size(); ++i) {
            int idx = g[v][i];
            if (!bridge[idx] && block[getTo(v, idx)] == -1) {
                dfsBlock(getTo(v, idx), bnum);
            }
        }
    }
};

Graph graph;

struct Tree {
    int N;
    vector <pair <int, int> > g[MAXN];
    long long innerDP[MAXN], outerDP[MAXN];
    long long dp[MAXN];

    void setN(int N) {
        this->N = N;

        for (int i = 0; i <= N; i++) {
            g[i].clear();
        }

        memset(innerDP, 0, sizeof(long long) * (N + 1));
        memset(outerDP, 0, sizeof(long long) * (N + 1));
        memset(dp, 0, sizeof(long long) * (N + 1));
    }

    void addEdge(int x, int y, int c) {
        g[x].emplace_back(y, c);
        g[y].emplace_back(x, c);
    }

    void dfsInnerDP(int v, int par = -1) {
        for (size_t i = 0; i < g[v].size(); ++i) {
            if (g[v][i].first == par) {
                g[v].erase(g[v].begin() + i);
                break;
            }
        }

        for (size_t i = 0; i < g[v].size(); ++i) {       
            int to = g[v][i].first;
            int cost = g[v][i].second;
            
            dfsInnerDP(to, v);

            innerDP[v] = max(innerDP[v], cost + innerDP[to]);
        }
    }

    #define f(x) (innerDP[g[v][x].first] + g[v][x].second)

    inline void dfsOuterDP(int v) {
        if (g[v].empty()) {
            return;
        }

        if (g[v].size() == 1) {
            int to = g[v][0].first;
            int cost = g[v][0].second;

            outerDP[to] = outerDP[v] + cost;
            dfsOuterDP(to);
        } else {
            // Searching for two maximums
            int mx1 = 0, mx2 = 1;
            if (f(1) > f(0)) {
                mx1 = 1, mx2 = 0;
            }

            for (size_t i = 2; i < g[v].size(); ++i) {
                if (f(i) > f(mx1)) {
                    mx2 = mx1;
                    mx1 = i;
                } else if (f(i) > f(mx2)) {
                    mx2 = i;
                }
            }

            // Calc outerDP
            for (size_t i = 0; i < g[v].size(); ++i) {
                int to = g[v][i].first;
                int cost = g[v][i].second;

                int mx = mx1;
                if ((int)i == mx1) {
                    mx = mx2;
                }

                outerDP[to] = max(f(mx), outerDP[v]) + cost;
            }

            // Recursive call
            for (size_t i = 0; i < g[v].size(); ++i) {  
                dfsOuterDP(g[v][i].first);
            }
        }
    }

    void printAns() {
        for (int i = 0; i < N; ++i) {
            dp[i] = max(innerDP[i], outerDP[i]);
        }

        int ans = 0;
        for (int i = 1; i < N; ++i) {
            if (dp[i] < dp[ans]) {
                ans = i;
            }
        }

        int anscity = -1;
        for (int i = 1; i <= graph.N; ++i) {
            if (dp[graph.block[i]] == dp[ans]) {
                anscity = i;
                break;
            }
        }

        printf("%d %I64d\n", anscity, dp[ans]);
    }

};

Tree tree;

int T, n, m, x, y, c;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m);

        graph.setN(n);

        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &x, &y, &c);
            
            graph.addEdge(x, y, c);
        }

        graph.dfsBridge();

        int bnum = 0;
        for (int i = 1; i <= n; i++) {
            if (graph.block[i] == -1) {
                graph.dfsBlock(i, bnum++);
            }
        }

        tree.setN(bnum);

        for (int idx = 0; idx < graph.lastEdge; idx++) {        
            if (graph.bridge[idx]) {
                int v1 = graph.block[graph.to[idx]];
                int v2 = graph.block[graph.from[idx]];
                int _cost = graph.cost[idx];

                tree.addEdge(v1, v2, _cost);
            }
        }

        tree.dfsInnerDP(0);
        tree.dfsOuterDP(0);

        tree.printAns();
    }

    return 0;
}
