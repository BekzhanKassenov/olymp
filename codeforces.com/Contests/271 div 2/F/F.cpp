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

int gcd(int a, int b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }

    return a + b;
}

int n, a[MAXN];
int t, l, r;
pair <int, int> mn[4 * MAXN];
int g[4 * MAXN];

void combine(pair <int, int>& a, const pair <int, int>& b) {
    if (a.first == b.first)
        a.second += b.second;

    if (a.first > b.first)
        a = b;
}

void build(int v, int l, int r) {
    if (l == r) {
        mn[v] = make_pair(a[l], 1);
        g[v] = a[l];
        return;
    }

    int mid = (l + r) >> 1;

    build(v << 1, l, mid);
    build((v << 1) + 1, mid + 1, r);

    mn[v] = mn[(v << 1) + 1];
    combine(mn[v], mn[v << 1]);

    g[v] = gcd(g[v << 1], g[(v << 1) + 1]);
}

pair <int, pair <int, int> > get(int v, int l, int r, int ql, int qr) {
    if (l > qr || ql > r)
        return make_pair(0, make_pair(INF, 0));

    if (ql <= l && r <= qr)
        return make_pair(g[v], mn[v]);

    int mid = (l + r) >> 1;

    pair <int, pair <int, int> > a(get(v << 1, l, mid, ql, qr));
    pair <int, pair <int, int> > b(get((v << 1) + 1, mid + 1, r, ql, qr));

    a.first = gcd(a.first, b.first);
    combine(a.second, b.second);

    return a;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    build(1, 1, n);

    scanf("%d", &t);

    while (t--) {
        scanf("%d%d", &l, &r);

        pair <int, pair <int, int> > p(get(1, 1, n, l, r));

        int ans = r - l + 1;
        if (p.first % p.second.first == 0)
            ans -= p.second.second;

        printf("%d\n", ans);
    }
    
    return 0;
}
