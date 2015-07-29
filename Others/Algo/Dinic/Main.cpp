#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;

const int maxn = 510;
const ll INF = 1ll << 62;

struct edge {
    int from, to;
    ll c, f;

    edge() { }

    edge(int from, int to, ll c) : from(from), to(to), c(c), f(0) { }
};

edge e[maxn * maxn];
vector <int> g[maxn];

int n, m, last, a, b, c;
int dist[maxn]; 
size_t last_ptr[maxn];
ll lim = INF;
int S, T;

void add_edge(int a, int b, ll c) {
    e[last] = edge(a, b, c);
    g[a].push_back(last++);

    e[last] = edge(b, a, 0);
    g[b].push_back(last++);
}

bool bfs() {
    queue <int> q;
    q.push(S);

    memset(dist, 255, sizeof dist);
    dist[S] = 0;

    while (!q.empty() && dist[T] == -1) {
        int v = q.front();
        q.pop();

        for (size_t i = 0; i < g[v].size(); i++) {
            int ind = g[v][i];

            if (dist[e[ind].to] == -1 && e[ind].c - e[ind].f >= lim) {
                dist[e[ind].to] = dist[v] + 1;
                q.push(e[ind].to);
            }
        }
    }

    return dist[T] != -1;
}

bool dfs(int v) {
    if (v == T)
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

            while (dfs(S)) {
                res += lim;
            }
        }
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);

    S = 0, T = n - 1;

    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        add_edge(--a, --b, c);
    }

    printf("%I64d", dinic());

    return 0;
}
