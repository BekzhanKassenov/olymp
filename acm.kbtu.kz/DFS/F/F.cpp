#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = (int)2e9;
int n, m;

int main() {
    freopen("f.in", "r", stdin);
    freopen("f.out", "w", stdout);

    scanf("%d%d", &n, &m);

    vector <int> who(n);

    for (int i = 0; i < n; i++)
        scanf("%d", &who[i]);

    vector <vector <int> > g(n);

    int a, b;

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);

        a--, b--;

        g[a].push_back(b);
        g[b].push_back(a);
    } 

    vector <int> d(n, INF);

    vector <int> pr(n, -1);

    d[0] = 0;

    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q;

    q.push(make_pair(0, 0));

    while (!q.empty()) {
        int v = q.top().second;
        int dist = q.top().first;

        q.pop();

        if (d[v] != dist)
            continue;

        for (size_t i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            int cost = 0;

            if (who[v] != who[to]) {
                if (v & 1)
                    cost = 2;
                else
                    cost = 1;   
            }

            if (d[v] + cost < d[to]) {
                d[to] = d[v] + cost;
                pr[to] = v;
                q.push(make_pair(d[to], to));
            }
        }
    }

    if (d[n - 1] == INF) {
        puts("impossible");
        return 0;
    }

    vector <int> ans;

    for (int i = n - 1; i != -1; i = pr[i])
        ans.push_back(i);

    printf("%d %d\n", d[n - 1], (int)ans.size());

    reverse(ans.begin(), ans.end());

    for (size_t i = 0; i < ans.size(); i++)
        printf("%d ", ans[i] + 1);

    return 0;
}
