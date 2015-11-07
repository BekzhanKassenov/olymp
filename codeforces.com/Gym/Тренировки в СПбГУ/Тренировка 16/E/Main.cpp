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
const int INF = 2000 * 1000 * 1000;
const int MOD = 1000 * 1000 * 1000 + 7;
const int MAXN = 300;
const int MAXM = (100 * 100 * 2 + 100) * 2;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct MinCostMaxFlow {
    // Edges
    int from[MAXM], to[MAXM];
    int cost[MAXM], flow[MAXM], cap[MAXM];
    int lastEdge;

    vector <int> g[MAXN];

    int phi[MAXN], dist[MAXN];
    int par[MAXN];

    MinCostMaxFlow() : lastEdge(0) { }

    void addEdge(int from, int to, int cap, int cost) {
        this->from[lastEdge] = from;
        this->to[lastEdge] = to;
        this->cap[lastEdge] = cap;
        this->flow[lastEdge] = 0;
        this->cost[lastEdge] = cost;
        g[from].push_back(lastEdge++);

        this->from[lastEdge] = to;
        this->to[lastEdge] = from;
        this->cap[lastEdge] = 0;
        this->flow[lastEdge] = 0;
        this->cost[lastEdge] = -cost;
        g[to].push_back(lastEdge++);
    }

    void fordBellman(int S) {
        for (int i = 0; i < MAXN; i++) {
            phi[i] = INF;
        }

        phi[S] = 0;
        for (int iter = 0; iter < MAXN - 1; iter++) {
            for (int i = 0; i < lastEdge; i++) {
                if (phi[from[i]] != INF) {
                    phi[to[i]] = min(phi[to[i]], phi[from[i]] + cost[i]);
                }
            }
        }
    }

    bool dijkstra(int S, int T) {
        for (int i = 0; i < MAXN; i++) {
            dist[i] = INF;
            par[i] = -1;
        }

        dist[S] = 0;
        priority_queue <pair <int, int>,
                        vector <pair <int, int> >,
                        greater <pair <int, int> > > q;

        q.emplace(0, S);

        while (!q.empty()) {
            int d = q.top().first;
            int v = q.top().second;

            q.pop();

            if (dist[v] != d) {
                continue;
            }

            for (int idx: g[v]) {
                if (cap[idx] <= flow[idx]) {
                    continue;
                }

                int weight = cost[idx] + phi[v] - phi[to[idx]];
                if (dist[to[idx]] > dist[v] + weight) {
                    dist[to[idx]] = dist[v] + weight;
                    par[to[idx]] = idx;
                    q.emplace(dist[to[idx]], to[idx]);
                }
            }
        }

        return par[T] != -1;
    }

    int getMinCostMaxFlow(int S, int T) {
        fordBellman(S);

        int result = 0;

        while (dijkstra(S, T)) {
            int pushFlow = INF;

            for (int i = T; par[i] != -1; i = from[par[i]]) {
                pushFlow = min(pushFlow, cap[par[i]] - flow[par[i]]);
            }

            for (int i = T; par[i] != -1; i = from[par[i]]) {
                flow[par[i]] += pushFlow;
                flow[par[i] ^ 1] -= pushFlow;

                result += 1ll * cost[par[i]] * pushFlow;
            }
        }

        return result;
    }
};

struct Place {
    int x, y;
    int cap;

    void read() {
        scanf("%d%d%d", &x, &y, &cap);
    }
};

MinCostMaxFlow minCostMaxFlow;
int n, m;
Place a[MAXN], b[MAXN];
int plan[MAXN][MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        a[i].read();
    }

    for (int i = 0; i < m; i++) {
        b[i].read();
    }

    int S = 0, T = n + m + 1;
    for (int i = 0; i < n; i++) {
        minCostMaxFlow.addEdge(S, i + 1, a[i].cap, 0);
    }

    for (int i = 0; i < m; i++) {
        minCostMaxFlow.addEdge(n + i + 1, T, b[i].cap, 0);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            minCostMaxFlow.addEdge(i + 1, n + j + 1, INF, abs(a[i].x - b[j].x) + abs(a[i].y - b[j].y) + 1);
        }
    }

    int ansOld = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            scanf("%d", &x);

            ansOld += 1ll * x * (abs(a[i].x - b[j].x) + abs(a[i].y - b[j].y) + 1);
        }
    }

    int ansNew = minCostMaxFlow.getMinCostMaxFlow(S, T);

    /*
    for (int i = 0; i < minCostMaxFlow.lastEdge; i += 2) {
        if (minCostMaxFlow.flow[i] != 0) 
        cout << minCostMaxFlow.from[i] << ' ' << minCostMaxFlow.to[i] << ' ' << minCostMaxFlow.cost[i] << ' ' << minCostMaxFlow.flow[i] << endl;
    }
    cout << endl;
    */

    if (ansNew < ansOld) {
        puts("SUBOPTIMAL");

        for (int i = 0; i < minCostMaxFlow.lastEdge; i += 2) {
            int aa = minCostMaxFlow.from[i];
            int bb = minCostMaxFlow.to[i];

            if (1 <= aa && aa <= n && n + 1 <= bb && bb <= n + m) {
                plan[aa - 1][bb - (n + 1)] = minCostMaxFlow.flow[i];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d ", plan[i][j]);
            }
            puts("");
        }
    } else {
        puts("OPTIMAL");
    }

    return 0;
}
