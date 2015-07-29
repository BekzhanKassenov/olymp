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
const int LG = 30;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

vector <int> g[MAXN];
int n, x, y;
int depth[MAXN], anc[MAXN][LG];
int tin[MAXN], tout[MAXN], timer;
int q, a, b;

void dfs(int v, int par = 1, int d = 0) {
    depth[v] = d;
    tin[v] = timer++;

    anc[v][0] = par;
    for (int i = 1; i < LG; i++) {
        anc[v][i] = anc[anc[v][i - 1]][i - 1];
    }

    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to != par) {
            dfs(to, v, d + 1);
        }
    }

    tout[v] = timer++;
}

bool ancestor(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int go_up(int a, int b) {
    for (int i = LG - 1; i >= 0; i--) {
        if (!ancestor(anc[a][i], b)) {
            a = anc[a][i];
        }
    }

    return a;
}

int lca(int a, int b) {
    int result = -1;

    if (ancestor(a, b)) {
        result = a;
    } else if (ancestor(b, a)) {
        result = b;
    } else {
        result = anc[go_up(a, b)][0];
    }

    return result;
}

int dist(int a, int b) {
    int l = lca(a, b);

    return depth[a] - depth[l] + depth[b] - depth[l];
}

int query(int a, int b) {
    int result = 0;    

    for (int i = 1; i <= n; i++) {
        if (dist(a, i) == dist(b, i)) {
            result++;
        }
    }

    return result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1);

    scanf("%d", &q);

    while (q--) {
        scanf("%d%d", &a, &b);

        printf("%d\n", query(a, b));
    }
    
    return 0;
}
