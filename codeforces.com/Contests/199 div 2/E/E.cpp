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
const int MAXN = 100010;
const int BSIZE = 330;
const int LG = 17;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

enum CTYPE { 
    BLUE,
    RED
};

struct Query {
    int type;
    int x;
};

Query q[MAXN];
int n, m;
vector <int> g[MAXN];
CTYPE color[MAXN];
int closest[MAXN];

void bfs() {
    queue <int> q;
    for (int i = 1; i <= n; i++) {
        closest[i] = INF;
        if (color[i] == RED) {
            q.push(i);
            closest[i] = 0;
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to: g[v]) {
            if (closest[to] > closest[v] + 1) {
                closest[to] = closest[v] + 1;
                q.push(to);
            }
        }
    }
}

int anc[LG][MAXN];
int tin[MAXN], tout[MAXN], timer;
int dist[MAXN];

void dfs(int v, int par = 1) {
    tin[v] = timer++;
    anc[0][v] = par;

    for (int i = 1; i < LG; i++) {
        anc[i][v] = anc[i - 1][anc[i - 1][v]];
    }

    for (int to: g[v]) {
        if (to != par) {
            dist[to] = dist[v] + 1;
            dfs(to, v);
        }
    }

    tout[v] = timer++;
}

bool ancestor(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b) {
    if (ancestor(a, b)) {
        return a;
    }

    if (ancestor(b, a)) {
        return b;
    }

    for (int i = LG - 1; i >= 0; i--) {
        if (!ancestor(anc[i][a], b)) {
            a = anc[i][a];
        }
    }

    return anc[0][a];
}

int get_dist(int a, int b) {
    int l = lca(a, b);

    return dist[a] + dist[b] - 2 * dist[l];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    color[1] = RED;
    dfs(1);
    for (int i = 0; i < m; i++) {
        if (i % BSIZE == 0) {
            bfs();
        }

        scanf("%d%d", &q[i].type, &q[i].x);

        if (q[i].type == 1) {
            color[q[i].x] = RED;
        } else {
            int ans = closest[q[i].x];

            for (int j = i - i % BSIZE; j < i; j++) {
                if (q[j].type == 1) {
                    ans = min(ans, get_dist(q[i].x, q[j].x));
                }
            }

            printf("%d\n", ans);
        }
    }

    return 0;
}
