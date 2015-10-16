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
const int MAXN = 200010;
const int LG = 18;

inline long long sqr(int n) {
    return 1ll * (n + 1) * n / 2;
}

int n, q;
vector <int> g[MAXN];

int anc[MAXN][LG];
int size[MAXN], rest[MAXN];
int tin[MAXN], tout[MAXN], timer = 1;

long long dp[MAXN][LG], sumsqr[MAXN];

void dfs(int v, int par = 1) {
    tin[v] = timer++;

    anc[v][0] = par;

    for (int i = 1; i < LG; i++) {
        anc[v][i] = anc[anc[v][i - 1]][i - 1];
    }

    size[v] = 1;
    for (int to: g[v]) {
        if (to != par) {
            dfs(to, v);

            size[v] += size[to];
            sumsqr[v] += sqr(size[to]);
        }
    }

    rest[v] = n - size[v];

    tout[v] = timer++;
}

void dfsDP(int v) {
    if (v != 1) {
        dp[v][0] = sumsqr[anc[v][0]] - sqr(size[v]);
    }

    for (int i = 1; i < LG; i++) {
        dp[v][i] = dp[v][i - 1] + dp[anc[v][i - 1]][i - 1];
    }

    for (int to: g[v]) {
        if (to != anc[v][0]) {
            dfsDP(to);
        }
    }
}

bool upper(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b) {
    if (upper(a, b)) {
        return a;
    }

    if (upper(b, a)) {
        return b;
    }

    for (int i = LG - 1; i >= 0; i--) {
        if (!upper(anc[b][i], a)) {
            b = anc[b][i];
        }
    }

    return anc[b][0];
}

long long solveOne(int a, int b) {
    assert(upper(a, b));

    long long ans = 0;
    for (int i = LG - 1; i >= 0; i--) {
        if (!upper(anc[b][i], a)) {
            ans += dp[b][i];
            b = anc[b][i];
        }
    }

    return ans;
}

int get_preanc(int a, int b) {
    assert(upper(a, b));

    for (int i = LG - 1; i >= 0; i--) {
        if (!upper(anc[b][i], a)) {
            b = anc[b][i];
        }
    }

    return b;
}

long long query(int a, int b) {
    if (a == b) {
        return sumsqr[a] + sqr(rest[a]);
    }

    int l = lca(a, b);

    if (l == b) {
        swap(a, b);
    }

    if (l == a) {
        int preancb = get_preanc(a, b);

        return solveOne(a, b) + sqr(rest[a]) + sumsqr[b] + sumsqr[a] - sqr(size[preancb]);
    }

    int preanca = get_preanc(l, a);
    int preancb = get_preanc(l, b);

    long long ans = solveOne(l, a) + solveOne(l, b);
    ans += sqr(rest[l]) + sumsqr[a] + sumsqr[b];
    ans += sumsqr[l] - sqr(size[preanca]) - sqr(size[preancb]);

    return ans;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d", &n, &q);

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);

        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1);
    dfsDP(1);

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d%d", &x, &y);

        cout << query(x, y) << endl;
    }

    return 0;
}
