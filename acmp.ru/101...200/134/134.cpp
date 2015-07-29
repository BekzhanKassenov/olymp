#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 110;
const int INF = (int)2e9;

struct edge {
    int to;
    int start, finish;

    void read() { 
        scanf("%d%d%d", &start, &to, &finish);
    }

    bool operator < (const edge& rhs) const {
        return start < rhs.start;
    }
};

vector <edge> g[maxn];
int n, s, f, m, v, dist[maxn];
edge temp;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d%d%d", &n, &s, &f, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d", &v);
        temp.read();
        g[v].push_back(temp);
    }

    for (int i = 1; i <= n; i++) {
        sort(g[v].begin(), g[v].end());
        dist[i] = INF;
    }

    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q;

    q.push(make_pair(0, s));
    dist[s] = 0;

    while (!q.empty()) {
        int d = q.top().first;
        int v = q.top().second;
        q.pop();

        if (dist[v] != d)
            continue;

        temp.start = d;

        for (size_t i = 0; i < g[v].size(); i++) {
            if (g[v][i].start < d)
                continue;

            if (dist[g[v][i].to] > g[v][i].finish) {
                dist[g[v][i].to] = g[v][i].finish;
                q.push(make_pair(g[v][i].finish, g[v][i].to));
            }
        }
    }

    if (dist[f] < INF)
        printf("%d\n", dist[f]);
    else
        puts("-1");

    return 0;
}
