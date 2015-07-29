#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int c[600][600], f[600][600], anc[600], n, m, a, b, sz;

bool bfs(int v, int st, vector <int>& path) {
    path.clear();
    memset(anc, -1, sizeof(anc));

    queue <int> q;

    q.push(v);
    anc[v] = -2;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            if (anc[i] == -1 && c[cur][i] && c[cur][i] - f[cur][i] > 0) {
                q.push(i);
                anc[i] = cur;
            }
        }
    }

    if (anc[st] == -1)
        return false;

    while (st != -2) {
        path.push_back(st);
        st = anc[st];
    }   

    reverse(path.begin(), path.end());

    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &sz);

        a--, b--;

        c[a][b] = sz;
    }

    vector <int> path;

    while (bfs(0, n - 1, path)) {
        int cur_flow = 10000000;

        for (int i = 1; i < (int)path.size(); i++)
            cur_flow = min(cur_flow, c[path[i - 1]][path[i]] - f[path[i - 1]][path[i]]);

        for (int i = 1; i < (int)path.size(); i++) {
            f[path[i - 1]][path[i]] += cur_flow;
            f[path[i]][path[i - 1]] -= cur_flow; 
        }
    }

    long long ans = 0;

    for (int i = 0; i < n; i++)
        if (f[0][i] > 0)
            ans += f[0][i];

    cout << ans;

    return 0;
}
