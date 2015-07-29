#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 100010;
const int INF = 16714589 + 1;
int table[17][maxn], level[maxn];
int n, m, u, v, ans;

void build() {
    for (int i = 1; i < n; i++)
        table[0][i] = (23 * table[0][i - 1] + 21563) % 16714589;

    level[0] = 0;

    for (int i = 2; i <= n; i++) {
        level[i] = level[i >> 1] + 1;
    }

    int add = 1, r;

    for (int lev = 1; lev <= level[n]; lev++) {
        r = add;
        for (int i = 0; i < n; i++) {
            table[lev][i] = table[lev - 1][i];

            if (r <= n && table[lev - 1][i] > table[lev - 1][r])
                table[lev][i] = table[lev - 1][r];

            r++;
        }
        add <<= 1;      
    }
}

// Returns minimal element in range [l, r)
inline int get_min(int l, int r) {
    return min(table[level[r - l]][l], table[level[r - l]][r - (1 << level[r - l])]);
}

int main() {                     
    freopen("sparse.in", "r", stdin);
    freopen("sparse.out", "w", stdout);

    cin >> n >> m >> table[0][0] >> u >> v;
    u--, v--;

    build();

    for (int i = 1; i <= m; i++) {
        ans = get_min(min(u, v), max(u, v) + 1);
        if (i != m) {
            u = (17 * (u + 1) + 751 + ans + 2 * i) % n;
            v = (13 * (v + 1) + 593 + ans + 5 * i) % n;
        }
    }

    cout << u + 1 << ' ' << v + 1 << ' ' << ans;

    return 0;
}
