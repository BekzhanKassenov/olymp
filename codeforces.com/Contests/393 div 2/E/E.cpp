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

int mn[4 * MAXN];
int add[4 * MAXN];
int val[MAXN];

void push(int v, int l, int r) {
    if (add[v] == 0) {
        return;
    }

    if (l != r) {
        add[2 * v] += add[v];
        mn[2 * v] += add[v];

        add[2 * v + 1] += add[v];
        mn[2 * v + 1] += add[v];

        add[v] = 0;
    }
}

void update(int v, int l, int r, int ql, int qr, int val) {
    push(v, l, r);
    if (ql > r || l > qr) {
        return;
    }

    if (ql <= l && r <= qr) {
        add[v] += val;
        mn[v] += val;
        return;
    }

    int mid = (l + r) / 2;
    update(2 * v, l, mid, ql, qr, val);
    update(2 * v + 1, mid + 1, r, ql, qr, val);

    mn[v] = min(mn[2 * v], mn[2 * v + 1]);
}

int goDown(int v, int l, int r) {
    push(v, l, r);
    
    if (l == r) {
        return l;
    }

    int mid = (l + r) / 2;
    if (mn[2 * v + 1] >= 0) {
        return goDown(2 * v, l, mid);
    }

    return goDown(2 * v + 1, mid + 1, r);
}

void print(int v, int l, int r) {
    push(v, l, r);
    if (l == r) {
        printf("a[%d]=%d\n", l, mn[l]);
        return;
    }

    int mid = (l + r) / 2;
    print(2 * v, l, mid);
    print(2 * v + 1, mid + 1, r);

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int pos, type;
        scanf("%d%d", &pos, &type);

        if (type == 0) {
            update(1, 1, n, 1, pos, 1);
        } else {
            scanf("%d", &val[pos]);
            update(1, 1, n, 1, pos, -1);
        }

        //print(1, 1, n);

        if (mn[1] >= 0) {
            puts("-1");
            continue;
        }

        printf("%d\n", val[goDown(1, 1, n)]);
    }

    return 0;
}
