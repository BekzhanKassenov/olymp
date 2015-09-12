/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "journey"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long INF = 2000ll * 1000 * 1000 * 1000 * 1000;
const int MOD = 1000 * 1000 * 1000 + 7;
const int MAXN = 2010;
const int MAXM = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Edge {
    int from, to;
    int cost;
};

int n, s, t;
int m, x, y, l;
    
struct Graph {
    Edge e[MAXM];
    int lastEdge;

    vector <int> g[MAXN];
    int color[MAXN];
    int in[MAXN];

    bool used[MAXN];
    long long dist[MAXN];
    
    int N;

    Graph() {
        lastEdge = 0;
        memset(color, 0, sizeof color);
        memset(used, false, sizeof used);
        memset(in, 0, sizeof in);

        for (int i = 0; i < MAXN; i++) {
            dist[i] = INF;
        }
    }

    void addEdge(int from, int to, int cost) {
        e[lastEdge] = {from, to, cost};
        g[from].push_back(lastEdge++);
    }

    bool cycle(int v) {
        color[v] = 1;

        for (int idx: g[v]) {
            if (color[e[idx].to] == 0 && cycle(e[idx].to)) {
                return true;
            } else if (color[e[idx].to] == 1) {
                return true;
            }

            in[e[idx].to]++;
        }

        color[v] = 2;
        return false;
    }

    void dijkstra(int S) {
        dist[S] = 0;

        for (int i = 1; i <= N; i++) {
            int pos = -1;
            for (int j = 1; j <= N; j++) {
                if (!used[j] && (pos == -1 || dist[pos] > dist[j])) {
                    pos = j;
                }
            }

            if (pos == -1 || dist[pos] == INF) {
                break;
            }

            used[pos] = true;
            for (int idx: g[pos]) {
                int to = e[idx].to;
                dist[to] = min(dist[to], dist[pos] + e[idx].cost);
            }
        }
    }

    void runDP(int S) {
        queue <int> q;
        memset(dist, 0, sizeof dist);

        q.push(S);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int idx: g[v]) {
                int to = e[idx].to;

                dist[to] = max(dist[to], dist[v] + e[idx].cost);
                in[to]--;

                if (in[to] == 0) {
                    q.push(to);
                }
            }
        }
    }
};

Graph g1, g2, g3;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d%d%d", &n, &s, &t);

    g1.N = n;
    g2.N = n;
    g3.N = 2 * n;

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &x, &y, &l);
        g1.addEdge(x, y, l);
        g1.addEdge(y, x, l);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &x, &y, &l);
        g2.addEdge(x, y, l);
        g2.addEdge(y, x, l);
    }

    g1.dijkstra(t);
    g2.dijkstra(t);

    for (int i = 0; i < g1.lastEdge; i++) {
        int from = g1.e[i].from;
        int to = g1.e[i].to;
        if (g1.dist[from] > g1.dist[to]) {
            g3.addEdge(from, to + n, g1.e[i].cost);
        }
    }

    for (int i = 0; i < g2.lastEdge; i++) {
        int from = g2.e[i].from;
        int to = g2.e[i].to;
        if (g2.dist[from] > g2.dist[to]) {
            g3.addEdge(from + n, to, g2.e[i].cost);
        }
    }

    if (g3.cycle(s)) {
        puts("-1");
        return 0;
    }

    g3.runDP(s); //???

    long long ans = max(g3.dist[t], g3.dist[t + n]);

    printf("%I64d\n", ans);

    return 0;
}
