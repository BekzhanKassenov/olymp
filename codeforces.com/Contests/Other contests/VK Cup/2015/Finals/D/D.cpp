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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int parent[4 * MAXN];
int flag[4 * MAXN];
int n;

int get_parent(int v) {
    if (parent[v] == v) {
        return v;
    }

    return v = get_parent(parent[v]);
}

void unite(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a != b) {
        parent[b] = a;
    }
}

void apply(int v, int par) {
    if (flag[v] == -1) {
        flag[v] = par;
    } else {
        unite(par, flag[v]);
        flag[v] = par;
    }
}

void push(int v, int l, int r) {
    if (flag[v] != -1) {
        if (l != r) {
            unite(v, 2 * v);
            unite(v, 2 * v + 1);

            apply(2 * v, flag[v]);
            apply(2 * v + 1, flag[v]);
        }

        unite(v, flag[v]);
    }
}

void update(int v, int l, int r, int ql, int qr, int par) {
    if (l > qr || ql > r) {
        return;
    }

    if (ql <= l && r <= qr) {
        apply(v, par);
        push(v, l, r);
        return;
    }

    push(v, l, r);
    int mid = (l + r) / 2;
    update(2 * v, l, mid, ql, qr, par);
    update(2 * v + 1, mid + 1, r, ql, qr, par);
}

int get(int v, int l, int r, int pos) {
    push(v, l, r);

    if (l == r) {
        return get_parent(v);
    }

    int mid = (l + r) / 2;

    if (pos <= mid) {
        return get(2 * v, l, mid, pos);
    }

    return get(2 * v + 1, mid + 1, r, pos);
}

void query1(int x, int y) {
    int par = get(1, 0, n - 1, x);
    update(1, 0, n - 1, x, x, par);
    update(1, 0, n - 1, y, y, par);
}

void query2(int x, int y) {
    int par = get(1, 0, n - 1, x);
    update(1, 0, n - 1, x, y, par);
}

int query3(int x, int y) {
    x = get(1, 0, n - 1, x);
    y = get(1, 0, n - 1, y);

    return get_parent(x) == get_parent(y);
}

int q, type, x, y;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &q);

    for (int i = 0; i < 4 * MAXN; i++) {
        parent[i] = i;
        flag[i] = -1;
    }

    while (q--) {
        scanf("%d%d%d", &type, &x, &y);

        x--, y--;

        if (type == 1) {
            query1(x, y);
        } else if (type == 2) {
            query2(x, y);
        } else {
            if (query3(x, y)) {
                puts("YES");
            } else {
                puts("NO");
            }
        }

        /*
        cout << endl;
        for (int i = 0; i < 27; i++) {
            cout << parent[i] << ' ';
        }
        cout << endl;
        */
    }
    
    return 0;
}
                             