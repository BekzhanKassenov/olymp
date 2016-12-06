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
vector <int> g[MAXN];
int a[MAXN], b[MAXN];
int color[MAXN];

void dfs(int v, int c = 1) {
    color[v] = c;
    for (int to : g[v]) {
        if (color[to] == 0) {
            dfs(to, 3 - c);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int u = 2 * i - 1;
        int v = 2 * i;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d%d", a + i, b + i);

        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }

    for (int i = 1; i <= 2 * n; i++) {
        if (color[i] == 0) {
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", color[a[i]], color[b[i]]);
    }

    return 0;
}
