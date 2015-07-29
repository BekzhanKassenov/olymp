#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 20010;

vector <int> g[MAXN];
int tin[MAXN], fup[MAXN], timer;
int block[MAXN], bsize[MAXM], block_last;
bool is_cut[MAXN], used[MAXN];
int n, m, x, y;

void dfs(int v, int p = 0) {
    used[v] = true;
    tin[v] = fup[v] = ++timer;
    int child_num = 0;

    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];

        if (to == p) {
            continue;
        }

        if (used[to]) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            child_num++;

            if (fup[to] >= tin[v] && p != 0) {
                is_cut[v] = true;
            }
        }
    }

    if (p == 0 && child_num > 1) {
        is_cut[v] = true;
    }
}

void bfs(int s, int bnum) {
    used[s] = true;
    block[s] = bnum;

    queue <int> q;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (size_t i = 0; i < g[v].size(); i++) {
            int to = g[v][i];

            if (!used[to] && !is_cut[to]) {
                used[to] = true;
                block[to] = bnum;
                q.push(to);
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }

    memset(used, false, sizeof used);

    for (int i = 1; i <= n; i++) {
        if (!used[i] && !is_cut[i]) {
            bfs(i, block_last++);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (is_cut[i]) {

        } else {
            
        }
    }

    return 0;
}
