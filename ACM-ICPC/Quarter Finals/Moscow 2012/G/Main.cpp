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
const int MAXN = 100100;
const int LG = 18;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Edge {
    int from, to;
};

Edge e[MAXN];

vector <int> g[MAXN];

int up[MAXN], down[MAXN];
int anc[MAXN][LG];
int tin[MAXN], tout[MAXN], timer;
int depth[MAXN];
int n;

bool ancestor(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

void dfs(int v, int u, int dn, int par = 0, int d = 0) {
    up[v] = up[par] + u;
    down[v] = down[par] + dn;

    tin[v] = timer++;
    depth[v] = d;

    anc[v][0] = par;
    for (int i = 1; i < LG; i++) {
        anc[v][i] = anc[anc[v][i - 1]][i - 1];
    }

    for (int idx: g[v]) {
        if (e[idx].from == anc[v][0] || e[idx].to == anc[v][0]) {
            continue;
        }

        if (e[idx].from == v) {
            dfs(e[idx].to, 0, 1, v, d + 1);
        } else {
            dfs(e[idx].from, 1, 0, v, d + 1);
        }
    }

    tout[v] = timer++;
}

int getLCA(int a, int b) {
    if (ancestor(a, b)) {
        return a;
    }   

    if (ancestor(b, a)) {
        return b;
    }   

    for (int i = LG - 1; i >= 0; i--) {
        if (anc[a][i] != 0 && !ancestor(anc[a][i], b)) {
            a = anc[a][i];
        }
    }

    return anc[a][0];
}   

bool goesUp(int a, int b) {
    return up[a] - up[b] == depth[a] - depth[b];
}

bool goesDown(int a, int b) {
    return down[b] - down[a] == depth[b] - depth[a];
}

bool query(int a, int b) {
    int l = getLCA(a, b);

    if (l == a) {
        return goesDown(a, b);
    }

    if (l == b) {
        return goesUp(a, b);
    }

    return goesUp(a, l) && goesDown(l, b);
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &e[i].from, &e[i].to);

        g[e[i].from].push_back(i);
        g[e[i].to].push_back(i);
    }

    dfs(1, 0, 0);

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);

        if (query(x, y)) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    
    return 0;
}
