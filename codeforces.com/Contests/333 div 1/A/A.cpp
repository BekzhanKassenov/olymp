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
const int MAXN = 410;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

enum EDGE {
    BUS,
    TRAIN
};

int n, m;
EDGE g[MAXN][MAXN];
int dist[MAXN];

int bfs(EDGE type) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    dist[1] = 0;
    queue <int> q;
    q.push(1);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (i != v && g[v][i] == type && dist[i] > dist[v] + 1) {
                dist[i] = dist[v] + 1;
                q.push(i);
            }
        }
    }

    if (dist[n] == INF) {
        return -1;
    }

    return dist[n];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u][v] = TRAIN;
        g[v][u] = TRAIN;
    }

    if (g[1][n] == TRAIN) {
        printf("%d\n", bfs(BUS));
    } else {
        printf("%d\n", bfs(TRAIN));
    }
    
    return 0;
}
