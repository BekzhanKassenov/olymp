#include <iostream>
#include <numeric>
#include <cstdio>
#include <vector>

using namespace std;

#define all(x) (x).begin(), (x).end()

const int MAXN = 200010;

int n, m, x, y;
int tin[MAXN], fup[MAXN], timer;
int size[MAXN], rest[MAXN];
long long ans[MAXN];
bool used[MAXN];
vector <int> g[MAXN];

void dfs(int v, int par = -1) {
    used[v] = true;
    size[v] = 1;
    rest[v] = n - 1;
    ans[v] = n - 1;

    tin[v] = fup[v] = timer++;
    int chnum = 0;
    bool cut = false;
    vector <int> sizes;

    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];

        if (to == par) {
            continue;
        }

        if (used[to]) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            dfs(to, v);
            size[v] += size[to];
            fup[v] = min(fup[v], fup[to]);
            chnum++;

            if (fup[to] >= tin[v]) {
                cut = true;
                sizes.push_back(size[to]);
                rest[v] -= size[to];
            }
        }
    }

    if (cut) {
        sizes.push_back(rest[v]);
        long long sum = accumulate(all(sizes), 0);
        for (size_t i = 0; i < sizes.size(); i++) {
            sum -= sizes[i];
            ans[v] += sum * sizes[i];
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

    dfs(1);

    for (int i = 1; i <= n; i++) {
        printf("%I64d\n", ans[i]);
    }

    return 0;
}
