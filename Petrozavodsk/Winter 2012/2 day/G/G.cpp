#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int INF = (int)1e9;
const int maxn = 100010;

vector <int> g[maxn];
int dist[maxn];
bool used[maxn];
int n, m, x, y, u, v;

void bfs(int v) {
    queue <int> q;

    memset(used, false, sizeof used);
    q.push(v);
    used[v] = true;


    for (int i = 0; i < n; i++)
        dist[i] = INF;
    dist[v] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (size_t i = 0; i < g[cur].size(); i++) {
            int to = g[cur][i];

            if (!used[to]) {
                dist[to] = dist[cur] + 1;
                q.push(to);
                used[to] = true;
            }
        }
    }
}

int main() {
    #ifdef Local
        freopen("in", "r", stdin);
    #endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        g[--x].push_back(--y);
        g[y].push_back(x);
    }

    scanf("%d%d", &u, &v);
    u--, v--;

    bfs(u);
    int d = dist[v];

    for (size_t i = 0; i < g[u].size(); i++)
        if (g[u][i] == v) {
            g[u].erase(g[u].begin() + i);
            break;
        }
    for (size_t i = 0; i < g[v].size(); i++)
        if (g[v][i] == u) {
            g[v].erase(g[v].begin() + i);
            break;
        }

    bfs(u);

    if (dist[v] == INF) {
        cout << "Infinity";
    } else {
        cout << dist[v] - d;
    }
    return 0;

}
