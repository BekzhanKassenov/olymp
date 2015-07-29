/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 200010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, m, t, timer = -1, x, y;
int a[maxn], tin[maxn], tout[maxn], tree[2][maxn], fl[2][4 * maxn], level[maxn];
vector <int> g[maxn];

void dfs(int v, bool gl = false, int pr = -1) {
    level[v] = gl;
    tin[v] = ++timer;

    for (size_t i = 0; i < g[v].size(); i++) {
        if (g[v][i] != pr) {
            dfs(g[v][i], gl ^ true, v);
        }
    }

    tout[v] = timer;
}

void push(int t[], int flag[], int v, int l, int r) {
    if (l > r)
        return;
    else if (l < r) {
        flag[v << 1] += flag[v];
        flag[(v << 1) + 1] += flag[v];
    } else 
        t[l] += flag[v];

    flag[v] = 0;
} 

void update(int t[], int flag[], int v, int l, int r, int z_l, int z_r, int val) {
    if (l > r || z_l > r || z_r < l)
        return;

    push(t, flag, v, l, r);
    
    if (l >= z_l && r <= z_r) {
        flag[v] += val;
        push(t, flag, v, l, r);
    } else {
        int mid = (l + r) >> 1;

        update(t, flag, v << 1,       l,       mid, z_l, z_r, val);
        update(t, flag, (v << 1) + 1, mid + 1, r,   z_l, z_r, val);
    }
}

int get(int t[], int flag[], int v, int l, int r, int pos) {
    push(t, flag, v, l, r);

    if (l > r || pos < l || pos > r)
        return 0;

    if (l == r)
        return t[l];

    int mid = (l + r) >> 1;

    if (pos <= mid)
        return get(t, flag, v << 1, l, mid, pos);

    return get(t, flag, (v << 1) + 1, mid + 1, r, pos);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &x, &y);
        g[--x].push_back(--y);
        g[y].push_back(x);
    }

    dfs(0);

    for (int i = 0; i < n; i++) {
        update(tree[level[i]], fl[level[i]], 1, 0, n - 1, tin[i], tin[i], a[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &t);     

        if (t == 1) {
            scanf("%d%d", &x, &y);
            x--;
            update(tree[level[x]],     fl[level[x]],     1, 0, n - 1, tin[x], tout[x], y);
            update(tree[level[x] ^ 1], fl[level[x] ^ 1], 1, 0, n - 1, tin[x], tout[x], -y);
        } else {
            scanf("%d", &x);
            x--;
            printf("%d\n", get(tree[level[x]], fl[level[x]], 1, 0, n - 1, tin[x]));
        }
    }

    return 0;
}
