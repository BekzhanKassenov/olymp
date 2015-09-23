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
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;
const ull BASE = 37;
const ull MOD = 1000 * 1000 * 1000 + 7;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

ull tree[4 * MAXN];
ll flag[4 * MAXN];
ull power[MAXN], sum[MAXN];
ull a[MAXN];

int n, m, k;

void push(int v, int l, int r) {
    if (flag[v] != -1) {
        if (l < r) {
            flag[2 * v] = flag[v];
            flag[2 * v + 1] = flag[v];
        }

        tree[v] = (MOD + sum[r] - sum[l - 1]) % MOD * flag[v] % MOD;
        flag[v] = -1;
    }
}

void build(int v, int l, int r) {
    flag[v] = -1;

    if (l == r) {
        tree[v] = a[l] * power[l] % MOD;
        return;
    }
    
    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);

    tree[v] = (tree[2 * v] + tree[2 * v + 1]) % MOD;
}

ull get(int v, int l, int r, int ql, int qr) {

    push(v, l, r);
    
    if (ql > r || l > qr) {
        return 0;
    }

    if (ql <= l && r <= qr) {
        return tree[v];
    }

    int mid = (l + r) / 2;

    ull result = (get(2 * v, l, mid, ql, qr) + get(2 * v + 1, mid + 1, r, ql, qr)) % MOD;

    return result;
}

void update(int v, int l, int r, int ql, int qr, int val) {
    push(v, l, r);

    if (ql > r || l > qr) {
        return;
    }

    if (ql <= l && r <= qr) {
        flag[v] = val;
        push(v, l, r);
        return;
    }

    int mid = (l + r) / 2;
    update(2 * v, l, mid, ql, qr, val);
    update(2 * v + 1, mid + 1, r, ql, qr, val);

    tree[v] = (tree[2 * v] + tree[2 * v + 1]) % MOD;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d\n", &n, &m, &k);
    
    for (int i = 1; i <= n; i++) {
        char c;
        scanf("%c", &c);

        a[i] = c - '0';
    }

    power[0] = 1;
    sum[0] = 1;
    for (int i = 1; i <= n; i++) {
        power[i] = power[i - 1] * BASE % MOD;
        sum[i] = (sum[i - 1] + power[i]) % MOD;
    }

    build(1, 1, n);

    for (int i = 0; i < m + k; i++) {
        int type, l, r, x;

        scanf("%d%d%d%d", &type, &l, &r, &x);

        if (type == 1) {
            update(1, 1, n, l, r, x);
        } else {
            int len = (r - l + 1);

            if (len == x) {
                puts("YES");
            } else {
                ull sum1 = get(1, 1, n, l, r - x);
                ull sum2 = get(1, 1, n, l + x, r);
                
                if (sum1 * power[x] % MOD == sum2) {
                    puts("YES");
                } else {
                    puts("NO");
                }
            }
        }
    }

    return 0;
}
