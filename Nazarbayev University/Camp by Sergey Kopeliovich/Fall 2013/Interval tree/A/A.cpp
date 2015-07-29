#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 1e7 + 10;
const int MOD1 = (1 << 16);
const int MOD2 = 1 << 30;
int a[maxn], n, m, x, y, z, t, b;

void build() {
    for (int i = 2; i <= n; i++)
        a[i] = (x * a[i - 1] % MOD1 + y) % MOD1;

    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];
}

inline int get_sum(int l, int r) {
    return a[r] - a[l - 1];
}

int main() {
    freopen("sum0.in", "r", stdin);
    freopen("sum0.out", "w", stdout);

    cin >> n >> x >> y >> a[1];

    cin >> m >> z >> t >> b;

    build();

    long long ans = 0;

    int c1, c2;

    for (int i = 0; i < m; i++) {
        c1 = b % n;
        b = (z * b % MOD2 + t) % MOD2;
        c2 = b % n;
        b = (z * b % MOD2 + t) % MOD2;

        ans += get_sum(min(c1, c2) + 1, max(c1, c2) + 1);
    }

    cout << ans;

    return 0;
}
