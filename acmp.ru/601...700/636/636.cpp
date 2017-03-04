#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 50010;

int n;
vector <pair <int, int> > g[2][MAXN];
vector <pair <int, int> > apps[MAXN];
int dist[2][MAXN];

void add_edge(int u, int v, bool within) {
    if (u != v) {
        g[false][u].emplace_back(within, v);
        g[false][v].emplace_back(within, u);    

        if (within) {
            g[true][u].emplace_back(true, v);
            g[true][v].emplace_back(true, u);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        dist[0][i] = dist[1][i] = 1e9;

        int a_num, a_pos;
        scanf("%d%d", &a_num, &a_pos);

        int nx = (i == n) ? 1 : (i + 1);
        add_edge(i, nx, false);
        
        apps[a_num].emplace_back(a_pos, i);
    }

    for (int i = 0; i < MAXN; i++) {
        auto& app = apps[i];

        sort(app.begin(), app.end());

        for (size_t i = 0; i < app.size(); i++) {
            add_edge(app[i].second, app[(i + 1) % app.size()].second, true);
        }
    }

    queue <pair <bool, int> > q;
    q.emplace(false, 1);
    dist[false][1] = 0;

    while (!q.empty()) {
        bool b = q.front().first;
        int v = q.front().second;
        q.pop();

        for (const auto& to : g[b][v]) {
            if (dist[to.first][to.second] > dist[b][v] + 1) {
                dist[to.first][to.second] = dist[b][v] + 1;
                q.push(to);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", min(dist[1][i], dist[0][i]));
    }

    puts("");
    return 0;
}
