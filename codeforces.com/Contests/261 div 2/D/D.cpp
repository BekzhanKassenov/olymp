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
const int maxn = 1000100;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, a[maxn];
int cntl[maxn], cntr[maxn], t[4 * maxn];
ll ans;
map <int, int> cnt;

void update(int v, int l, int r, int pos, int val) {
    if (l > r || pos < l || pos > r)
        return;

    t[v] += val;

    if (l != r) {
        int mid = (l + r) >> 1;
        update(v << 1, l, mid, pos, val);
        update((v << 1) + 1, mid + 1, r, pos, val);
    }
}

ll get(int v, int l, int r, int ql, int qr) {
    if (l > r || ql > qr || ql > r || l > qr)
        return 0;

    if (ql <= l && r <= qr)
        return t[v];

    int mid = (l + r) >> 1;
    
    return get(v << 1, l, mid, ql, qr) + 
           get((v << 1) + 1, mid + 1, r, ql, qr);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
        cntl[i] = cnt[a[i]];
    }

    cnt.clear();

    for (int i = n; i > 0; i--) {
        cnt[a[i]]++;
        cntr[i] = cnt[a[i]];
        update(1, 1, n, cntr[i], 1);
    }

    for (int i = 1; i <= n; i++) {
        update(1, 1, n, cntr[i], -1);
        ans += get(1, 1, n, 1, cntl[i] - 1);
    }

    printf("%I64d\n", ans);

    return 0;
}
