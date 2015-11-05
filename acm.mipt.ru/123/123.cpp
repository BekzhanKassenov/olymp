#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 400010;

vector <int> g[MAXN];

int n, m;
int depth[MAXN];
int first[MAXN];
int order[2 * MAXN], t[8 * MAXN];
int tSize;

void dfs(int v, int p = -1, int d = 0) {
    first[v] = tSize;
    order[tSize++] = v;
    depth[v] = d;

    for (size_t i = 0; i < g[v].size(); i++) {
        if (g[v][i] != p) {
            dfs(g[v][i], v, d + 1);
            order[tSize++] = v;
        }
    }
}

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = order[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);

    int lidx = t[2 * v];
    int ridx = t[2 * v + 1];

    if (depth[lidx] < depth[ridx]) {
        t[v] = lidx;
    } else {
        t[v] = ridx;
    }
}

int get(int v, int l, int r, int ql, int qr) {
    if (l > qr || ql > r) {
        return -1;
    }

    if (ql <= l && r <= qr) {
        return t[v];
    }

    int mid = (l + r) / 2;
    int lidx = get(2 * v, l, mid, ql, qr);
    int ridx = get(2 * v + 1, mid + 1, r, ql, qr);

    if (lidx == -1 || ridx == -1) {
        return (lidx == -1) ? ridx : lidx;
    }

    if (depth[lidx] < depth[ridx]) {
        return lidx;
    }

    return ridx;
}

int lca(int x, int y) {
    int l = first[x];
    int r = first[y];

    if (l > r) {
        swap(l, r);
    }

    return get(1, 0, tSize - 1, l, r);
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0);

    build(1, 0, tSize - 1);

    scanf("%d", &m);

    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);

        printf("%d\n", lca(x, y));
    }

    return 0;
}