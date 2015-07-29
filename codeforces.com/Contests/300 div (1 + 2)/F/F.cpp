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

int n;
int a[MAXN];
vector <int> t[4 * MAXN];

void build(int v, int l, int r) {
    if (l == r) {
        t[v].push_back(a[l]);
        return;
    }

    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);

    t[v].resize(t[2 * v].size() + t[2 * v + 1].size());
    merge(all(t[2 * v]), all(t[2 * v + 1]), t[v].begin());
}

int get(int v, int l, int r, int ql, int qr, int val) {
    if (l > r || ql > r || l > qr) {
        return 0;
    }

    if (ql <= l && r <= qr) {
        return lower_bound(all(t[v]), val) - t[v].begin();
    }

    int mid = (l + r) / 2;

    return get(2 * v, l, mid, ql, qr, val) + 
           get(2 * v + 1, mid + 1, r, ql, qr, val);
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

    for (int k = 1; k < n; k++) {
        int ans = 0;
        for (int i = 1; k * (i - 1) + 2 <= n; i++) {
            int l = k * (i - 1) + 2;
            int r = min(n, k * i + 1);

            ans += get(1, 1, n, l, r, a[i]);
        }

        printf("%d ", ans);
    }

    puts("");

    return 0;
}
