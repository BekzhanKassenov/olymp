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
const int maxn = 100010;
const int LG = 20;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int t[LG][4 * maxn], flag[LG][4 * maxn], a[maxn];
int n, m, tp, l, r, x;

void build(int v, int l, int r, int row) {
    if (l >= r)
        return;

    if (l + 1 == r) {
        t[row][v] = (a[l] & (1 << row)) ? 1 : 0;
        return;
    }

    int mid = (l + r) >> 1;

    build((v << 1) + 1, l, mid, row);
    build((v << 1) + 2, mid, r, row);

    t[row][v] = t[row][(v << 1) + 1] + t[row][(v << 1) + 2];
}

void push(int v, int l, int r, int row) {
    if (l >= r || !flag[row][v])
        return;

    t[row][v] = r - l - t[row][v];
    flag[row][v] = 0;

    if (l + 1 < r) {
        flag[row][(v << 1) + 1] ^= 1;
        flag[row][(v << 1) + 2] ^= 1;
    }
}

int get_sum(int v, int l, int r, int ql, int qr, int row) {
    push(v, l, r, row);

    if (l >= r || ql >= r || l >= qr)
        return 0;

    if (ql <= l && r <= qr)
        return t[row][v];

    int mid = (l + r) >> 1;

    return get_sum((v << 1) + 1, l, mid, ql, qr, row) +
           get_sum((v << 1) + 2, mid, r, ql, qr, row);
}

void update(int v, int l, int r, int ql, int qr, int row) {
    push(v, l, r, row);

    if (l >= r || ql >= r || l >= qr)
        return;

    if (ql <= l && r <= qr) {
        flag[row][v] ^= 1;
        push(v, l, r, row);
        return;
    } 

    int mid = (l + r) >> 1;

    update((v << 1) + 1, l, mid, ql, qr, row);
    update((v << 1) + 2, mid, r, ql, qr, row);

    t[row][v] = t[row][(v << 1) + 1] + t[row][(v << 1) + 2];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < LG; i++)
        build(0, 0, n, i);

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &tp, &l, &r);

        l--;

        if (tp == 1) {
            long long res = 0;

            for (int j = 0; j < LG; j++) {
                res += (1ll << j) * get_sum(0, 0, n, l, r, j);
            }

            printf("%I64d\n", res);
        } else {
            scanf("%d", &x);

            for (int j = 0; j < LG; j++, x >>= 1) {
                if (x & 1)
                    update(0, 0, n, l, r, j);
            }
        }
    }

    return 0;
}
