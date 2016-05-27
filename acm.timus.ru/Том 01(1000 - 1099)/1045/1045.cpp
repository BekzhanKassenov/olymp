#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1010;

int n, start;
vector <int> g[MAXN];
bool win[MAXN];

bool dfs(int v, int par = 0) {
    win[v] = false;

    for (int to: g[v]) {
        if (to == par) {
            continue;
        }

        if (!dfs(to, v)) {
            win[v] = true;
        }   
    }

    return win[v];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &start);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);

        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (dfs(start)) {
        int num = -1;
        for (int to: g[start]) {
            if (!win[to] && (num == -1 || num > to)) {
                num = to;
            }
        }

        printf("First player wins flying to airport %d\n", num);
    } else {
        puts("First player loses");
    }

    return 0;
}
