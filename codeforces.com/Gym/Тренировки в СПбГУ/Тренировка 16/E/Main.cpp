/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File ""

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long INF = (int)1e14;
const int MOD = 1000 * 1000 * 1000 + 7;
const int MAXN = 300;
const int MAXM = 100 * 100 * 2 + 100;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct MinCostMaxFlow {
    // Edges 
    int from[MAXM], to[MAXM];
    int flow[MAXM], cap[MAXM], cost[MAXM];
    int lastEdge;

    vector <int> g[MAXN];

    long long dist[MAXN], phi[MAXN];
    bool used[MAXN];
    int minCap[MAXN], par[MAXN];

    void addEdge(int from, int to, int cap, int cost) {
        this->from[lastEdge] = from;
        this->to[lastEdge] = to;
        this->cap[lastEdge] = cap;
        this->cost[lastEdge] = cost;
        this->flow[lastEdge] = 0;
        g[from].push_back(lastEdge++);

        this->from[lastEdge] = to;
        this->to[lastEdge] = from;
        this->cap[lastEdge] = 0;
        this->cost[lastEdge] = -cost;
        this->flow[lastEdge] = 0;
        g[to].push_back(lastEdge++);
    }

    void fordBellman(int S) {
        queue <int> q;
        memset(used, false, sizeof used);
        for (int i = 0; i < MAXN; i++) {
            dist[i] = INF;
        }

        dist[S] = 0;
        q.push(S);
        used[S] = true;

        while (!q.empty()) {
            int v = q.front();
            used[v] = false;

            for (int idx: g[v]) {
                if (cap[idx] - flow[idx] > 0 && dist[to[idx]] > dist[v] + cost[idx]) {
                    dist[to[idx]] = dist[v] + cost[idx];

                    if (!used[to[idx]]) {
                        q.push(to[idx]);
                    }
                }
            }
        }
    }

    long long run(int S, int T) {
        memset(used, false, sizeof used);
        for (int i = 0; i < MAXN; i++) {
            dist[i] = INF;
            minCap[i] = INF;
            par[i] = -1;
        }

        dist[S] = 0;

        for (int i = 0; i < MAXN; i++) {
            int v = -1;
            for (int j = 0; j < MAXN; j++) {
                if (!used[j] && (v == -1 || dist[j] < dist[v])) {
                    v = j;
                }
            }

            used[v] = true;

            for (int idx: g[v]) {
                long long weight = cost[idx] + phi[v] - phi[to[idx]];
                if (cap[idx] - flow[idx] > 0 && dist[to[idx]] > dist[v] + weight) {
                    dist[to[idx]] = dist[v] + weight;
                    minCap[to[idx]] = min(cap[idx] - flow[idx], minCap[v]);
                    par[to[idx]] = idx;
                }
            }
        }

        if (dist[T] == INF) {
            return INF;
        }

        return minCap[T];
    }

    long long getMinCostMaxFlow(int S, int T) {
        long long result = 0;
        long long pushed;

        fordBellman();

        for (int i = 0; i < MAXN; i++) {
            phi[i] = dist[i];
        }

        while ((pushed = run(S, T)) != INF) {
            
            for (int i = par[T]; i != -1; i = par[from[i]]) {
                result += cost[idx] * pushed;
                flow[i] += pushed;
            }

            for (int i = 0; i < MAXN; i++) {
                phi[i] = min(phi[i] + dist[i], INF);
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

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        a[i].read();
    }

    scanf("%d", &m);
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
            minCostMaxFlow.addEdge(i + 1, n + j + 1, INF, abs(a[i].x - b[j].x) + abs(a[i].y - b[j].y));
        }
    }



    return 0;
}
