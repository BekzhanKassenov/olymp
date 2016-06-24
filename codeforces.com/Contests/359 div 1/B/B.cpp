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
const int MAXN = 300010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, q;
vector <int> g[MAXN];
int size[MAXN];
int ans[MAXN];

void dfs(int v) {
    size[v] = 1;
    for (int to: g[v]) {
        dfs(to);
        size[v] += size[to];
    }

    if (g[v].empty()) {
        ans[v] = v;
        return;
    }

    int largest = g[v][0];
    for (int to: g[v]) {
        if (size[to] > size[largest]) {
            largest = to;
        }
    }

    if (size[largest] * 2 < size[v]) {
        ans[v] = v;
    } else {
        ans[v] = ans[largest];
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &q);

    for (int i = 2; i <= n; i++) {
        int p;
        scanf("%d", &p);
        g[p].push_back(i);
    }

    dfs(1);

    while (q--) {
        int v;
        scanf("%d", &v);

        printf("%d\n", ans[v]);
    }

    return 0;
}
