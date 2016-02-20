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
const long long INF = 2e9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int k, q;
int cnum[MAXN];
int city[MAXN];
int dist[MAXN];

int gr[110][110];
bool used[110];

vector <pair <int, int> > g[MAXN];

void dijkstraNlogN(int start) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    dist[start] = 0;

    priority_queue <pair <int, int>,
                    vector <pair <int, int> >,
                    greater <pair <int, int> > > q;

    q.emplace(dist[start], start);

    while (!q.empty()) {
        int d = q.top().first;
        int v = q.top().second;

        q.pop();

        if (dist[v] != d) {
            continue;
        }

        for (const auto& edge: g[v]) {
            int to = edge.first;
            int len = edge.second;

            if (dist[to] > dist[v] + len) {
                dist[to] = dist[v] + len;
                q.emplace(dist[to], to);
            }
        }
    }
}

void dijkstraN2(int start) {
    for (int i = 0; i < k; i++) {
        dist[i] = INF;
    }

    memset(used, false, sizeof used);

    dist[start] = 0;

    for (int i = 0; i < k; i++) {
        int v = -1;
        for (int j = 0; j < k; j++) {
            if (dist[j] != INF && !used[j] && (v == -1 || dist[j] < dist[v])) {
                v = j;
            }
        }

        if (v == -1) {
            continue;
        }

        used[v] = true;
        for (int j = 0; j < k; j++) {
            if (dist[j] > dist[v] + gr[v][j] && gr[v][j] != INF) {
                dist[j] = dist[v] + gr[v][j];
            }
        }
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v, len;

        scanf("%d%d%d", &u, &v, &len);

        g[u].emplace_back(v, len);
        g[v].emplace_back(u, len);
    }

    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &city[i]);
        cnum[city[i]] = i;
    }

    for (int i = 0; i < k; i++) {
        dijkstraNlogN(city[i]);

        for (int j = 0; j < k; j++) {
            gr[i][j] = dist[city[j]];
        }
    }

    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int type, a, b;
        scanf("%d%d%d", &type, &a, &b);
        
        a = cnum[a];
        b = cnum[b];

        if (type == 1) {
            dijkstraN2(a);

            if (dist[b] == INF) {
                puts("-1");
            } else {
                printf("%d\n", dist[b]);
            }
        } else {
            int len;
            scanf("%d", &len);

            if (gr[a][b] > len) {
                gr[a][b] = len;
                gr[b][a] = len;
            }
        }
    }

    return 0;
}
