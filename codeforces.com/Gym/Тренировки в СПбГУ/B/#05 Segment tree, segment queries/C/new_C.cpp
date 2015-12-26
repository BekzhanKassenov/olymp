#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int maxn = 100010;

int a[maxn], flag[4 * maxn], n, m, l, r, val;
ll t[4 * maxn];
char c;

void push(int v, int l, int r) {
    if (l > r || flag[v] == -1)
        return;

    if (l < r) 
        flag[v << 1] = flag[(v << 1) + 1] = flag[v];

    t[v] = (r - l + 1) * 1ll * flag[v];
    flag[v] = -1;
}

void upd(int v, int l, int r, int z_l, int z_r, int val) {
    push(v, l, r);

    if (l > r || z_r < l || z_l > r)
        return;

    if (l >= z_l && r <= z_r) {
        flag[v] = val;
        push(v, l, r);
        return;
    }
    
    int mid = (l + r) >> 1;
    upd( v << 1,      l,       mid, z_l, z_r, val);
    upd((v << 1) + 1, mid + 1, r,   z_l, z_r, val);
    
    t[v] = t[v << 1] + t[(v << 1) + 1];
}

ll get(int v, int l, int r, int z_l, int z_r) {
    if (l > r || z_r < l || z_l > r)
        return 0ll;

    push(v, l, r);

    if (l >= z_l && r <= z_r)
        return t[v];

    int mid = (l + r) >> 1;

    return get(v << 1, l, mid, z_l, z_r) + get((v << 1) + 1, mid + 1, r, z_l, z_r);
}

int main() {
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);

    ios_base :: sync_with_stdio(false);

    cin >> n >> m;

    memset(flag, -1, sizeof flag);

    for (int i = 0; i < m; i++) {
        cin >> c >> l >> r;

        if (c == 'A') {
            cin >> val;
            upd(1, 0, n - 1, l - 1, r - 1, val);
        } else 
            cout << get(1, 0, n - 1, l - 1, r - 1) << endl;
    }

    return 0;
}
