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
const long long INF = (int)1e14;
const int MOD = 1000 * 1000 * 1000 + 7;
const int MAXN = 2 * 250 + 10;
const int MAXM = MAXN * MAXN;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct MinCostMaxFlow {
    int from[MAXM], to[MAXM];
    int flow[MAXM], cap[MAXM], cost[MAXM];
    int lastEdge;

    vector <int> g[MAXN];

    long long dist[MAXN], phi[MAXN];
    int par[MAXN];
    bool used[MAXN];

    MinCostMaxFlow() : lastEdge(0) { }

    void addEdge(int f, int t, int c, int w) {
        from[lastEdge] = f;
        to[lastEdge] = t;
        cap[lastEdge] = c;
        cost[lastEdge] = w;
        flow[lastEdge] = 0;
        g[f].push_back(lastEdge++);

        from[lastEdge] = t;
        to[lastEdge] = f;
        cap[lastEdge] = 0;
        cost[lastEdge] = -w;
        flow[lastEdge] = 0;
        g[t].push_back(lastEdge++);
    }

    void fordBellman(int S) {
        for (int i = 0; i < MAXN; i++) {
            dist[i] = INF;
        }

        dist[S] = 0;

        bool changed = true;

        while (changed) {
            changed = false;

            for (int i = 0; i < lastEdge; i++) {
                if (cap[i] - flow[i] > 0 && dist[to[i]] > dist[from[i]] + cost[i]) {
                    dist[to[i]] = dist[from[i]] + cost[i];
                    changed = true;
                }
            }
        }
    }

    // Shortest path
    bool run(int S, int T, vector <int>& path) {
        memset(used, false, sizeof used);
        memset(par, -1, sizeof par);

        for (int i = 0; i < MAXN; i++) {
            dist[i] = INF;
        }

        dist[S] = 0;

        for (int i = 0; i < MAXN; i++) {
            int v = -1;
            for (int j = 0; j < MAXN; j++) {
                if (!used[j] && (v == -1 || dist[j] < dist[v])) {
                    v = j;
                }
            }

            if (v == -1 || dist[v] == INF) {
                break;
            }

            used[v] = true;

            for (auto idx: g[v]) {
                long long weight = cost[idx] + phi[v] - phi[to[idx]];

                if (cap[idx] - flow[idx] > 0 && dist[to[idx]] > dist[v] + weight) {
                    dist[to[idx]] = dist[v] + weight;
                    par[to[idx]] = idx;
                }
            }
        }

        if (dist[T] == INF) {
            return false;
        }

        path.clear();

        for (int i = T; par[i] != -1; i = from[par[i]]) {
            path.push_back(par[i]);
        }

        return true;
    }

    int getMinCostMaxFlow(int S, int T) {
        int flowCost = 0;
        vector <int> path;

        fordBellman(S);

        for (int i = 0; i < MAXN; i++) {
            phi[i] = dist[i];
        }

        while (run(S, T, path)) {
            for (int i = 0; i < MAXN; i++) {
                phi[i] = min(phi[i] + dist[i], INF);
            }

            int minCap = INF;

            for (int idx: path) {
                minCap = min(minCap, cap[idx] - flow[idx]);
            }

            for (int idx: path) {
                flowCost += minCap * cost[idx];
                flow[idx] += minCap;
                flow[idx ^ 1] -= minCap;
            }
        }

        return flowCost;
    }
};

MinCostMaxFlow flow;
int n;
int a[250][250];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int S = 2 * n + 1;
    int T = S + 1;

    for (int i = 0; i < n; i++) {
        flow.addEdge(S, i, 1, 0);
    }

    for (int j = 0; j < n; j++) {
        flow.addEdge(j + n, T, 1, 0);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            flow.addEdge(i, j + n, 1, a[i][j]);
        }
    }

    printf("%d\n", flow.getMinCostMaxFlow(S, T));

    for (int idx = 0; idx < flow.lastEdge; idx += 2) {
        int i = flow.from[idx];
        int j = flow.to[idx];

        if (flow.flow[idx] == 1 && i != S && j != T) {
            printf("%d %d\n", i + 1, j - n + 1);
        }
    }

    return 0;
}
