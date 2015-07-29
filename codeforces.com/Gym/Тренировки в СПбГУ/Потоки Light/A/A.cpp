#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;

const int maxn = 510;

struct edge {
    int from, to;
    int c, f;

    edge() { }

    edge(int from, int to, int c, int f) : from(from), to(to), c(c), f(f) { }
};

int n, m, a, b, c, last, dist[maxn];
size_t last_ptr[maxn];
edge e[maxn * maxn];
vector <int> g[maxn];
ll lim = 1ll << 32;
queue <int> q;

void add_edge(int a, int b, int c, int d) {
    e[last] = edge(a, b, c, d);
    g[a].push_back(last);
    last++;
}

bool bfs() {
    memset(dist, 255, sizeof dist);
    q.push(0);
    dist[0] = 0;

    while (!q.empty() && dist[n - 1] == -1) {
        int v = q.front();
        q.pop();

        for (size_t i = 0; i < g[v].size(); i++) {
            int ind = g[v][i];

            if (dist[e[ind].to] == -1 && e[ind].c - e[ind].f >= lim) {
                q.push(e[ind].to);

                dist[e[ind].to] = dist[v] + 1;
            }
        } 
    }

    while (!q.empty())
        q.pop();

    return dist[n - 1] != -1;
}

bool dfs(int v) {
    if (v == n - 1)
        return true;

    for (; last_ptr[v] < g[v].size(); last_ptr[v]++) {
        int ind = g[v][last_ptr[v]];

        if (dist[e[ind].to] == dist[v] + 1 && e[ind].c - e[ind].f >= lim && dfs(e[ind].to)) {
            e[ind].f += lim;
            e[ind ^ 1].f -= lim;
            return true;
        }
    }

    return false;
}

ll dinic() {
    ll res = 0;

    while (lim > 0) {
        if (!bfs()) {
            lim >>= 1;
        } else {
            memset(last_ptr, 0, sizeof last_ptr);

            while (dfs(0)) {
               res += lim; 
            }
        }
    }

    return res;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);

        add_edge(--a, --b, c, 0);
        add_edge(b, a, 0, 0);

        add_edge(b, a, c, 0);
        add_edge(a, b, 0, 0);
    }

    cout << dinic() << endl;

    return 0;
}
