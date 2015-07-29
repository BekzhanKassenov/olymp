#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 100010;

vector <int> g[maxn];
int n, x, h, t, last;
int dist[maxn], par[maxn], ans[maxn];

void bfs(int st) {
    memset(dist, 255, sizeof dist);
    queue <int> q;
    q.push(st);  
    dist[st] = 0;
    
    for (int i = 1; i <= n; i++)
        par[i] = i;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (size_t i = 0; i < g[v].size(); i++) {
            if (dist[g[v][i]] == -1) {
                dist[g[v][i]] = dist[v] + 1;
                q.push(g[v][i]);
                par[g[v][i]] = v;
            }
        } 
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    scanf("%d", &h);
    last = h;

    for (int i = 0; i < n - 2; i++) {
        scanf("%d", &x);
        g[last].push_back(x);
        last = x;
    }

    scanf("%d", &t);
    g[last].push_back(t);
    last = 0;

    bfs(h);

    for (x = t; x != par[x]; x = par[x]) {
        ans[last++] = x;
    }

    ans[last++] = h;

    reverse(ans, ans + last);

    for (int i = 0; i < last; i++)
        printf("%d ", ans[i]);

    return 0;
}