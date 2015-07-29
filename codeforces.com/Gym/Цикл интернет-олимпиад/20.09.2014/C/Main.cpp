/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "army"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 + 3;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

long long a[MAXN], t[4 * MAXN];
int n, q, l, r, type;

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);

    t[v] = (t[2 * v] * t[2 * v + 1]) % MOD;
}

long long get(int v, int l, int r, int ql, int qr) {
    if (l > qr || ql > r || l > r)
        return 1ll;

    if (ql <= l && r <= qr)
        return t[v];

    int mid = (l + r) / 2;

    return (get(2 * v, l, mid, ql, qr) * get(2 * v + 1, mid + 1, r, ql, qr)) % MOD;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
        a[i] %= MOD;
    }

    for (int i = 0; i < 4 * MAXN; i++)
        t[i] = 1;

    build(1, 0, n - 1);

    scanf("%d", &q);
    while (q--) {
        scanf("%d%d%d", &type, &l, &r);
        l--, r--;
        
        if (type == 0) {
            for (int i = l; i <= r; i++) {
                a[i] = (a[i] + 1ll) % MOD;
            }

            build(1, 0, n - 1);
        } else {
            long long ans = get(1, 0, n - 1, l, r);
            
            printf("%I64d\n", ans);
        }
    }
    return 0;
}
