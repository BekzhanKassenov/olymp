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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

vector <pair <int, int> > g1[MAXN], g2[MAXN];
long long dist1[MAXN], dist2[MAXN];
int n, m, s, t;
int x, y, len;

void dijkstra(int S, const vector <pair <long long, int> >& g, long long dist[MAXN]) {
    memset(dist, -1, sizeof dist);
    dist[S] = 0;
    priority_queue <pair <long long, int>, 
                    vector <pair <long long, int> >,
                    greater <pair <long long, int> > > q;

    q.push(make_pair(0ll, S));

    while (!q.empty()) {
        int v = q.top().second;
        long long vdist = q.top().first;
        q.pop();

        if (vdist != dist[v]) {
            continue;
        }

        for (size_t i = 0; i < g[v].size(); i++) {
            int to = g[v][i].second;
            long long len = g[v][i].first;

            if (dist[to] == -1 || dist[to] > distv + len) {
                dist[to] = distv + len;
                q.push(make_pair(dist[to], to));
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d%d", &n, &m, &s, &t);

    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &x, &y, &len);

        g1[x].push_back(make_pair(len, y));
        g2[y].push_back(make_pair(len, x));
    }

    dijkstra(s, g1, dist1);
    dijkstra(t, g2, dist2);
    


    return 0;
}
