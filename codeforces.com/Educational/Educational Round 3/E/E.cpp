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
const int MAXN = 200010;
const int LG = 19;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Edge {
    int from, to, cost;
    int num;
    bool mst;
    long long weight;

    bool operator < (const Edge& e) const {
        return cost < e.cost;
    }

    int getOther(int v) const {
        if (v == from) {
            return to;
        }

        return from;
    }
};

inline bool numcmp(const Edge& e1, const Edge& e2) {
    return e1.num < e2.num;
}

Edge e[MAXN];
int n, m;

/**
 *  DSU implementation
 */
int DSUparent[MAXN];

int getParent(int v) {
    if (DSUparent[v] == v) {
        return v;
    }   

    return DSUparent[v] = getParent(DSUparent[v]);
}

void unite(int a, int b) {
    DSUparent[getParent(a)] = getParent(b);
}

/**
 * DFS, lca (binary lifting)
 */

vector <int> g[MAXN];
int tin[MAXN], tout[MAXN], timer;
int anc[LG][MAXN];
int dp[LG][MAXN];

void dfs(int v, int par = 1, int w = 0) {
    tin[v] = timer++;

    anc[0][v] = par;
    dp[0][v] = w;
    for (int i = 1; i < LG; i++) {
        anc[i][v] = anc[i - 1][anc[i - 1][v]];
        dp[i][v] = max(dp[i - 1][v], dp[i - 1][anc[i - 1][v]]);
    }

    for (int idx: g[v]) {
        int to = e[idx].getOther(v);

        if (to != par) {
            dfs(to, v, e[idx].cost);
        }
    }

    tout[v] = timer++;
}

bool ancestor(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lift(int a, int b) {
    int mx = 0;

    for (int i = LG - 1; i >= 0; i--) {
        if (!ancestor(anc[i][a], b)) {
            mx = max(mx, dp[i][a]);
            a = anc[i][a];
        }
    }

    return max(mx, dp[0][a]);
}

int getMax(int a, int b) {
    if (ancestor(a, b)) {
        return lift(b, a);
    }

    if (ancestor(b, a)) {
        return lift(a, b);
    }

    int l = a;
    for (int i = LG - 1; i >= 0; i--) {
        if (!ancestor(anc[i][l], b)) {
            l = anc[i][l];
        }
    }

    l = anc[0][l];

    return max(lift(a, l), lift(b, l));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &e[i].from, &e[i].to, &e[i].cost);
        e[i].mst = false;
        e[i].num = i;
        e[i].weight = 0;
    }

    for (int i = 1; i <= n; i++) {
        DSUparent[i] = i;
    }

    sort(e, e + m);

    long long mstWeight = 0;
    for (int i = 0; i < m; i++)  {
        if (getParent(e[i].from) != getParent(e[i].to)) {
            unite(e[i].from, e[i].to);
            e[i].mst = true;
            mstWeight += e[i].cost;
            g[e[i].from].push_back(i);
            g[e[i].to].push_back(i);
        }
    }

    dfs(1);

    for (int i = 0; i < m; i++) {
        if (e[i].mst) {
            e[i].weight = mstWeight;
        } else {
            e[i].weight = mstWeight - getMax(e[i].from, e[i].to) + e[i].cost;
        }
    }

    sort(e, e + m, numcmp);

    for (int i = 0; i < m; i++) {
        printf("%I64d\n", e[i].weight);
    }

    return 0;
}
