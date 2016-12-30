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

int n, x, y;
vector <int> g[MAXN];
char color[MAXN];
int size[MAXN];
bool used[MAXN];

void dfs(int v, int par = -1) {
    size[v] = 1;
    for (int to : g[v]) {
        if (to != par && !used[to]) {
            dfs(to, v);
            size[v] += size[to];
        }
    }
}

int getCentroid(int v, vector <int>& roots, int treeSize, int par = -1) {
    int mx = -1;
    for (int to : g[v]) {
        if (to != par && !used[to] && (mx == - 1 || size[to] > size[mx])) {
            mx = to;
        }
    }

    if (mx == -1 || size[mx] * 2 < treeSize) {
        for (int to: g[v]) {
            if (!used[to]) {
                roots.push_back(to);
            }
        }
        return v;
    }

    return getCentroid(mx, roots, treeSize, v);
}


void build(int root, char c) {
    dfs(root);

    vector <int> vec;
    int r = getCentroid(root, vec, size[root]);
    color[r] = c;
    used[r] = true;
    
    for (int v : vec) {
        dfs(v);
        build(v, c + 1);
    }
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

    build(1, 'A');

    for (int i = 1; i <= n; i++) {
        putchar(color[i]);
        putchar(" \n"[i == n]);
    }


    return 0;
}
