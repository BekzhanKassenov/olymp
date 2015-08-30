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
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
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

    int dist[MAXN], par[MAXN];
    bool inque[MAXN], used[MAXN];

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

    // Shortest path
    bool run(int S, int T, vector <int>& path) {
        deque <int> q;
        memset(dist, 255, sizeof dist);
        memset(par, 255, sizeof par);
        memset(inque, false, sizeof inque);
        memset(used, false, sizeof used);

        q.push_back(S);
        dist[S] = 0;
        inque[S] = true;
        used[S] = true;

        while (!q.empty()) {
            int v = q.front();
            q.pop_front();
            inque[v] = false;

            for (int& idx: g[v]) {
                if (cap[idx] - flow[idx] <= 0) {
                    continue;
                }

                int _to = to[idx];
                if (dist[_to] == -1 || (dist[_to] > dist[v] + cost[idx])) {
                    dist[_to] = dist[v] + cost[idx];
                    par[_to] = idx;

                    if (!inque[_to]) {
                        if (used[_to]) {
                            q.push_front(_to);
                        } else {
                            q.push_back(_to);
                        }

                        inque[_to] = true;
                        used[_to] = true;
                    }
                }
            }
        }

        path.clear();
        if (par[T] != -1) {
            for (int v = T; par[v] != -1; v = from[par[v]]) {
                path.push_back(par[v]);
            }

            return true;
        } else {
            return false;
        }
    }

    int getMinCostMaxFlow(int S, int T) {
        int flowCost = 0;
        vector <int> path;

        while (run(S, T, path)) {
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
