/****************************************
**          Solution by NU #2          **
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
const int MAXN = 10010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

priority_queue <int, vector <pair <int, int> >, greater <pair <int, int> > > q;
int n, m, A, K;
int x, y, cost;
int ans, b;
vector <pair <int, int> > g[MAXN];
int dist[MAXN];
int mndist[MAXN];
bool safe[MAXN];

void dijkstra(int v) {
    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[v] = 0;
    q.push(make_pair(0, v));
    
    if (safe[v]) {
        safe[v] = false;
        ans--;
    }

    while (!q.empty()) {
        int cur = q.top().second;
        int d = q.top().first;
        q.pop();

        if (d != dist[cur])
            continue;

        for (size_t i = 0; i < g[cur].size(); i++) {
            int to = g[cur][i].first;
            int cost = g[cur][i].second;
            int ndist = dist[cur] + cost;

            if (dist[to] > ndist) {
                if (dist[cur] + cost < K && (safe[to] || (!safe[to] && ndist < mndist[to]))) {
                    dist[to] = dist[cur] + cost;
                    q.push(make_pair(dist[to], to));
                    
                    if (safe[to]) {
                        safe[to] = false;
                        ans--;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
        mndist[i] = min(mndist[i], dist[i]);
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    while (scanf("%d%d%d%d", &n, &m, &A, &K) && (n || m || A || K)) {
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            mndist[i] = INF;
        }

        memset(safe, true, sizeof safe);
        ans = n;

        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &x, &y, &cost);
            g[x].push_back(make_pair(y, cost));
            g[y].push_back(make_pair(x, cost));
        }

        for (int i = 0; i < A; i++) {
            scanf("%d", &b);
            dijkstra(b);
            printf("%d\n", ans);
        }

        puts("");
    }
    
    return 0;
}
