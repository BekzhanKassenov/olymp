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
const int M = 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

bool prime(int n) {
    if (n == 0 || n == 1) {
        return false;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

bitset <M> maskprime, mask;
int n, m;
int a[MAXN];

vector <int> g[MAXN];
int tin[MAXN], tout[MAXN], timer;
int ver[MAXN];

void dfs(int v, int p = -1) {
    tin[v] = ++timer;
    ver[timer] = v;

    for (int to: g[v]) {
        if (to != p) {
            dfs(to, v);
        }
    }

    tout[v] = timer;
}

bitset <M> tree[4 * MAXN];
int flag[4 * MAXN];

void push(int v, int l, int r) {
    if (l < r) {
        flag[2 * v] = (flag[2 * v] + flag[v]) % m;
        flag[2 * v + 1] = (flag[2 * v + 1] + flag[v]) % m;
    }

    if (flag[v] != 0) {
        tree[v] = ((tree[v] << flag[v]) | (tree[v] >> (m - flag[v]))) & mask;
    }

    flag[v] = 0;
}

void build(int v, int l, int r) {
    if (l == r) {
        tree[v].set(a[ver[l]]);
    } else {
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);

        tree[v] = tree[2 * v] | tree[2 * v + 1];
    }
}

void update(int v, int l, int r, int ql, int qr, int val) {
    push(v, l, r);

    if (l > qr || ql > r) {
        return;
    }

    if (ql <= l && r <= qr) {
        flag[v] = (flag[v] + val) % m;
        push(v, l, r);

        return;
    }

    int mid = (l + r) / 2;

    update(2 * v,     l,      mid, ql, qr, val);
    update(2 * v + 1, mid + 1,  r, ql, qr, val);

    tree[v] = tree[2 * v] | tree[2 * v + 1];
}

void get(int v, int l, int r, int ql, int qr, bitset <M>& res) {
    if (l > qr || ql > r) {
        return;
    }

    push(v, l, r);
    if (ql <= l && r <= qr) {
        res |= tree[v];
        return;
    }

    int mid = (l + r) / 2;
    get(2 * v,     l,      mid, ql, qr, res);
    get(2 * v + 1, mid + 1,  r, ql, qr, res);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] %= m;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    for (int i = 0; i < m; i++) {
        if (prime(i)) {
            maskprime.set(i);
        }

        mask.set(i);
    }

    build(1, 1, timer);

    int q;
    scanf("%d", &q);

    bitset <M> res;

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int v, x;
            scanf("%d%d", &v, &x);

            update(1, 1, timer, tin[v], tout[v], x);
        } else {
            int v;
            scanf("%d", &v);

            res.reset();
            get(1, 1, timer, tin[v], tout[v], res);

            /*
            for (int i = 0; i < m; i++) {
                cerr << res[i];
            }
            cerr << endl;
            */

            res &= maskprime;

            printf("%d\n", (int)res.count());
        }
    }

    return 0;
}
