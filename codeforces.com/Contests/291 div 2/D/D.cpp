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

int n, m, k;

struct Item {
    int a[5];

    Item() {
        memset(a, 0, sizeof a);
    }

    int sum() {
        int res = 0;
        for (int i = 0; i < m; i++) {
            res += a[i];
        }

        return res;
    }
};

Item a[MAXN], t[4 * MAXN];
Item result;
int reslen = 0;

Item combine(Item l, const Item& r) {
    for (int i = 0; i < m; i++) {
        l.a[i] = max(l.a[i], r.a[i]);
    }

    return l;
}

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = a[l];
        return;
    }

    int mid = (l + r) / 2;

    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);

    t[v] = combine(t[2 * v], t[2 * v + 1]);
} 

Item get_max(int v, int l, int r, int ql, int qr) {
    if (ql > r || l > qr) {
        return Item();
    }

    if (ql <= l && r <= qr) {
        return t[v];
    }

    int mid = (l + r) / 2;

    return combine(get_max(2 * v, l, mid, ql, qr),
                   get_max(2 * v + 1, mid + 1, r, ql, qr));
}

void bin_search(int pos) {
    int l = pos, r = n - 1;
    Item res;

    while (l <= r) {
        int mid = (l + r) / 2;

        Item temp = get_max(1, 0, n - 1, pos, mid);

        if (temp.sum() <= k) {
            res = temp;

            if (mid - pos + 1 > reslen) {
                reslen = mid - pos + 1;
                result = res;
            }

            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &(a[i].a[j]));
        }
    }
    build(1, 0, n - 1);

    for (int i = 0; i < n; i++) {
        bin_search(i);
    }

    for (int i = 0; i < m; i++) {
        printf("%d ", result.a[i]);
    }

    return 0;
}
