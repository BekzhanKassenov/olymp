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
const int MAXN = 100010;
const long long INF = (long long)1e18;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

// Segment Tree
long long a[MAXN];
long long flag[4 * MAXN], t[4 * MAXN];

void push(int v, int l, int r) {
    if (flag[v] == 0) {
        return;
    }

    if (l == r) {
        a[l] -= flag[v];
        t[v] = a[l];
    } else {
        t[2 * v] -= flag[v];
        t[2 * v + 1] -= flag[v];

        flag[2 * v] += flag[v];
        flag[2 * v + 1] += flag[v];
    }

    flag[v] = 0;
}

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);

    t[v] = min(t[2 * v], t[2 * v + 1]);
}

void update_range(int v, int l, int r, int ql, int qr, long long val) {
    push(v, l, r);
    
    if (ql > r || l > qr) {
        return;
    }

    if (ql <= l && r <= qr) {
        t[v] -= val;
        flag[v] += val;
        return;
    }

    int mid = (l + r) / 2;
    update_range(2 * v, l, mid, ql, qr, val);
    update_range(2 * v + 1, mid + 1, r, ql, qr, val);

    t[v] = min(t[2 * v], t[2 * v + 1]);
}

int get_leftmost(int v, int l, int r) {
    push(v, l, r);

    if (t[v] > 0) {
        return -1;
    }

    if (l == r) {
        return l;
    }

    int mid = (l + r) / 2;
    if (t[2 * v] <= 0) {
        return get_leftmost(2 * v, l, mid);
    }

    return get_leftmost(2 * v + 1, mid + 1, r);
}

void set_inf(int v, int l, int r, int pos) {
    push(v, l, r);

    if (l == r) {
        a[l] = INF;
        t[v] = a[l];
        return;
    }

    int mid = (l + r) / 2;

    if (pos <= mid) {
        set_inf(2 * v, l, mid, pos);
    } else {
        set_inf(2 * v + 1, mid + 1, r, pos);
    }

    t[v] = min(t[2 * v], t[2 * v + 1]);
}

int n, m;

// Fenwick
int tree[MAXN];

void update(int pos) {
    for (int i = pos; i < n; i |= i + 1) {
        tree[i]++;
    }
}

int sum(int pos) {
    int result = 0;
    for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
        result += tree[i];
    }

    return result;
}

void process(int l, int r, int e) {
    update_range(1, 0, n - 1, l, r, e);

    int pos;
    while ((pos = get_leftmost(1, 0, n - 1)) != -1) {
        set_inf(1, 0, n - 1, pos);
        update(pos);
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
    }

    build(1, 0, n - 1);

    for (int i = 0; i < m; i++) {
        int type, l, r, delta;
        scanf("%d", &type);

        if (type == 0) {
            scanf("%d%d%d", &l, &r, &delta);

            process(l - 1, r - 1, delta);
        } else {
            scanf("%d%d", &l, &r);

            printf("%d\n", sum(r - 1) - sum(l - 2));
        }
    }

    return 0;
}
