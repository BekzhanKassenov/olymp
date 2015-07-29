#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define tim first
#define stat second
#define chnum first
#define chpos second

const int maxn = 110;
const int INF = (int)2e9;

int n, finish, m, x, t;
vector <pair <int, int> > ways[maxn], g[maxn];
int dist[maxn], size[maxn];

struct cmp {
    bool operator () (const pair <int, int>& a,
                      const pair <int, int>& b) {
        return ways[a.chnum][a.chpos].tim < ways[b.chnum][b.chpos].tim;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d%d%d", &n, &finish, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d", &size[i]);

        ways[i].resize(size[i]);

        for (int j = 0; j < size[i]; j++) {
            scanf("%d%d", &ways[i][j].stat, &ways[i][j].tim);

            g[ways[i][j].stat].push_back(make_pair(i, j));
        }
    }

    for (int i = 1; i <= n; i++) {
        sort(all(g[i]), cmp());
        dist[i] = INF;
    }

    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q;

    q.push(make_pair(0, 1));
    dist[1] = 0;

    while (!q.empty()) {
        int v = q.top().stat;
        int d = q.top().tim;
        q.pop();

        if (d != dist[v])
            continue;

        for (size_t i = 0; i < g[v].size(); i++) {
            int chain = g[v][i].chnum;
            int pos = g[v][i].chpos;

            if (ways[chain][pos].tim < d)
                continue;

            for (int j = pos; j < size[chain]; j++) {
                int to = ways[chain][j].stat;

                if (dist[to] > ways[chain][j].tim) {
                    dist[to] = ways[chain][j].tim;
                    q.push(ways[chain][j]);
                }
            }
        }
    }

    if (dist[finish] < INF)
        printf("%d\n", dist[finish]);
    else
        puts("-1");

    return 0;
}
