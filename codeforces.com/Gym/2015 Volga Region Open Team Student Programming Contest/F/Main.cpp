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
const int MAXN = 500;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Edge {
    int to, cap, flow, cost;
};

struct MinCostFlow {
    int dist[MAXN], par[MAXN];
    int lastE, par_e[MAXN];
    int id[MAXN];
    int q[MAXN], qh, qt;

    bool inque[MAXN];
    vector <int> g[MAXN];
    Edge e[MAXN * 10];
    
    MinCostFlow() {
        lastE = 0;
    }

    void add_edge(int from, int to, int cap, int cost) {
        e[lastE] = {to, cap, 0, cost};
        g[from].push_back(lastE);
        lastE++;

        e[lastE] = {from, 0, 0, -cost};
        g[to].push_back(lastE);
        lastE++;
    }

    void runLevit(int S, int T, vector <int>& path) {
        path.clear();
        memset(dist, 255, sizeof dist);
        memset(par, 255, sizeof par);
        memset(par_e, 255, sizeof par_e);
        memset(id, 0, sizeof id);
        qh = qt = 0;

        dist[S] = 0;
        inque[S] = true;
        q[qt++] = S;

        while (qh != qt) {
            int v = q[qh++];
            id[v] = 2;

            if (qh == MAXN) {
                qh = 0;
            }

            for (size_t i = 0; i < g[v].size(); i++) {
                int index = g[v][i];
                Edge &edge = e[index];

                if (edge.cap - edge.flow > 0) {
                    if (dist[edge.to] == -1 || dist[edge.to] > dist[v] + edge.cost) {
                        dist[edge.to] = dist[v] + edge.cost;
                        par[edge.to] = v;
                        par_e[edge.to] = g[v][i];

                        if (id[edge.to] == 0) {
                            q[qt] = edge.to;
                            qt++;

                            if (qt == MAXN) {
                                qt = 0;
                            }
                        } else if (id[edge.to] == 2) {
                            qh--;
                            if (qh < 0) {
                                qh = MAXN - 1;
                            }

                            q[qh] = edge.to;
                        }

                        id[edge.to] = 1;
                    }
                }
            }
        }

        if (par[T] == -1) {
            return;
        }

        for (int i = T; i != S; i = par[i]) {
            path.push_back(par_e[i]);
        }

        reverse(all(path));
    }

    int get_flow(int S, int T, int max_flow) {
        int cost = 0, flow = 0;
        vector <int> path;

        while (flow < max_flow) {
            runLevit(S, T, path);

            if (path.empty()) {
                break;
            }

            int add_flow = INF;
            for (size_t i = 0; i < path.size(); i++) {
                const Edge &edge = e[path[i]];
                add_flow = min(add_flow, edge.cap - edge.flow);
            }

            for (size_t i = 0; i < path.size(); i++) {
                Edge &edge = e[path[i]];
                Edge &back_edge = e[path[i] ^ 1];

                edge.flow += add_flow;
                back_edge.flow -= add_flow;

                cost += edge.cost * add_flow;
            }

            flow += add_flow;
        }

        return cost;
    }
};

int n, k;
int S, T;
int X, Y;
int p[MAXN], q[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d %d", &k, &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    MinCostFlow flow1, flow2;

    S = 0, T = 1;
    X = 2, Y = 3;

    /*
    ==================================
        Flow 1
    ==================================
    */

    flow1.add_edge(S, X, (k + 1) / 2, 0);
    flow1.add_edge(S, Y, k / 2, 0);

    for (int i = 0; i < n; i++) {
        flow1.add_edge(X, 4 + i, 1, p[i]);
    }

    for (int i = 0; i < n; i++) {
        flow1.add_edge(Y, 4 + i, 1, q[i]);
    }

    for (int i = 0; i < n; i++) {
        flow1.add_edge(4 + i, T, 1, 0);
    }

    /*
    ==================================
        Flow 2
    ==================================
    */

    flow2.add_edge(S, X, k / 2, 0);
    flow2.add_edge(S, Y, (k + 1) / 2, 0);

    for (int i = 0; i < n; i++) {
        flow2.add_edge(X, 4 + i, 1, p[i]);
    }

    for (int i = 0; i < n; i++) {
        flow2.add_edge(Y, 4 + i, 1, q[i]);
    }

    for (int i = 0; i < n; i++) {
        flow2.add_edge(4 + i, T, 1, 0);
    }

    printf("%d\n", min(flow1.get_flow(S, T, k), flow2.get_flow(S, T, k)));
    
    return 0;
}
