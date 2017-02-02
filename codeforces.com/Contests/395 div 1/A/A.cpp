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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
vector <int> g[MAXN];
int color[MAXN];
bool good[MAXN];

void dfs1(int v, int par = -1) {
    good[v] = true;
    for (int to : g[v]) {
        if (to != par) {
            dfs1(to, v);
            if (!good[to]) {
                good[v] = false;
            } else {
                good[v] &= (color[to] == color[v]);
            }
        }
    }
}

int dfs2(int v, int par = -1) {
    int bad = -1;
    for (int to : g[v]) {
        if (to != par && !good[to]) {
            if (bad != -1) {
                return -1;
            }

            bad = to;
        }
    }

    if (bad == -1) {
        return v;
    }

    bool go = true;
    if (par != -1) {
        go &= color[v] == color[par];
    }
    for (int to : g[v]) {
        if (to != par && to != bad) {
            go &= color[to] == color[v];
        }
    }

    if (!go) {
        return -1;
    }

    return dfs2(bad, v);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &color[i]);
    }

    dfs1(1);
    int v = dfs2(1);

    if (v == -1) {
        puts("NO");
        return 0;
    }

    puts("YES");
    printf("%d\n", v);
    
    return 0;
}
