/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 300010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Edge {
    int from, to;
    long long cost;

    void read() {
        scanf("%d %d", &from, &to);
        scanf("%I64d", &cost);
    }

    int other(int v) {
        int result = -1;

        if (v == from) {
            result = to;
        } else if (v == to) {
            result = from;
        } else {
            assert(false);
        }

        return result;
    }
};

int n, m;
int seed;
Edge e[MAXN];
vector <int> g[MAXN];
vector <int> par[MAXN];
long long dist[MAXN];
int ans[MAXN];
long long weight;

void dijkstra(int v) {
    memset(dist, 255, sizeof dist);
    dist[v] = 0;
    priority_queue <pair <long long, int>, 
                    vector <pair <long long, int> >, 
                    greater <pair <long long, int> > > q;

    q.push(make_pair(0, v));

    while (!q.empty()) {
        long long d = q.top().first;
        long long ver = q.top().second;

        q.pop();

        if (dist[ver] != d) {
            continue;
        }

        for (size_t i = 0; i < g[ver].size(); i++) {
            int to = e[g[ver][i]].other(ver);
            long long cost = e[g[ver][i]].cost;

            if (dist[to] == -1 || dist[to] > dist[ver] + cost) {
                dist[to] = dist[ver] + cost;
                par[to].clear();
                par[to].push_back(g[ver][i]);
                q.push(make_pair(dist[to], to));
            } else if (dist[to] == dist[ver] + cost) {
                par[to].push_back(g[ver][i]);
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i++) {
        e[i].read();
        g[e[i].from].push_back(i);
        g[e[i].to].push_back(i);
    }

    memset(ans, 255, sizeof ans);

    scanf("%d", &seed);

    dijkstra(seed);

    for (int i = 1; i <= n; i++) {
        if (i != seed) {
            long long anscost = -1;
            
            for (size_t j = 0; j < par[i].size(); j++) {
                long long cost = e[par[i][j]].cost;

                if (anscost == -1 || anscost > cost) {
                    ans[i] = par[i][j];
                    anscost = cost;
                }
            }

            weight += anscost;
        }
    }

    printf("%I64d\n", weight);

    for (int i = 1; i <= n; i++) {
        if (i != seed) {
            printf("%d ", ans[i]);
        }
    }

    return 0;
}
