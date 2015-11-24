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
const int LG = 18;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n, m;

struct DSU {
    int parent[MAXN];
    int size[MAXN];

    int getParent(int v) {
        if (parent[v] == v) {
            return v;
        }

        return parent[v] = getParent(parent[v]);
    }

    bool unite(int a, int b) {
        a = getParent(a);
        b = getParent(b);

        if (a == b) {
            return false;
        }

        if (size[a] > size[b]) {
            size[a] += size[b];
            parent[b] = a;
        } else {
            size[b] += size[a];
            parent[a] = b;
        }

        return true;
    }

    void clear() {
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
};

DSU dsu;
vector <pair <int, int> > g[MAXN];
int tin[MAXN], tout[MAXN], timer;
int anc[LG][MAXN];
int dp[LG][MAXN];
bool used[MAXN];

// Queries
int node1[MAXN], node2[MAXN], moment[MAXN];
int lastQ;

void dfs(int v, int par, int _time) {
    tin[v] = timer++;

    used[v] = true;

    anc[0][v] = par;
    dp[0][v] = _time;

    for (int i = 1; i < LG; i++) {
        anc[i][v] = anc[i - 1][anc[i - 1][v]];
        dp[i][v] = max(dp[i - 1][v], dp[i - 1][anc[i - 1][v]]);
    }

    for (const auto& edge: g[v]) {
        int to = edge.first;
        int ntime = edge.second;

        if (to != par) {
            dfs(to, v, ntime);
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

int lift(int a, int l) {
    if (a == l) {
        return 0;
    }

    int mx = 0;
    for (int i = LG - 1; i >= 0; i--) {
        if (!ancestor(anc[i][a], l)) {
            mx = max(mx, dp[i][a]);
            a = anc[i][a];
        }
    }

    return max(mx, dp[0][a]);
}

int get_max(int a, int b) {
    int l = lca(a, b);

    return max(lift(a, l), lift(b, l));
}

void clear() {
    memset(used, false, sizeof(used[0]) * (n + 1));
    dsu.clear();
    timer = 0;
    lastQ = 0;

    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m);

        clear();

        for (int i = 1; i <= m; i++) {
            int type;
            scanf("%d", &type);

            if (type == 1) {
                int u, v;
                scanf("%d%d", &u, &v);

                if (dsu.unite(u, v)) {
                    g[u].emplace_back(v, i);
                    g[v].emplace_back(u, i);
                }

            } else {
                scanf("%d%d", &node1[lastQ], &node2[lastQ]);
                moment[lastQ] = i;
                lastQ++;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                dfs(i, i, 0);
            }
        }

        for (int i = 0; i < lastQ; i++) {
            if (dsu.getParent(node1[i]) != dsu.getParent(node2[i])) {
                puts("-1");
                continue;
            }

            int mx = get_max(node1[i], node2[i]);

            if (mx < moment[i]) {
                printf("%d\n", mx);
            } else {
                puts("-1");
            }
        }
    }

    return 0;
}
