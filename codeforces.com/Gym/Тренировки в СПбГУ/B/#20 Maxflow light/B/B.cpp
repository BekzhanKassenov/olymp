#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 2 * 10010;
const int MAXM = 4 * 110000;
const long long INF = 1ll << 62;

int par[MAXN];
long long suma[MAXN], sumb[MAXN];

int get_par(int v) {
    if (par[v] == v) {
        return v;
    }

    return par[v] = get_par(par[v]);
}

void unite(int a, int b) {
    a = get_par(a);
    b = get_par(b);

    if (a != b) {
        par[a] = b;
    }
}

int n, m, x, y;
int a[MAXN], b[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i <= 2 * n + 1; i++) {
        par[i] = i;
        suma[i] = sumb[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        unite(x, y + n);
    }

    for (int i = 1; i <= n; i++) {
        suma[get_par(i)] += a[i];
        sumb[get_par(i + n)] += b[i];
    }

    long long ans = 0;
    for (int i = 0; i <= 2 * n + 1; i++) {
        ans += min(suma[i], sumb[i]);
    }

    printf("%I64d\n", ans);

    return 0;
}
