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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Comp {
    bool hasCap;
    int nodes;
    int edges;
    int num;
};

int f(int n) {
    return n * (n - 1) / 2;
}

int n, m;
vector <int> g[MAXN];
bool used[MAXN];
bool capital[MAXN];

void dfs(int v, Comp& ans) {
    used[v] = true;
    ans.hasCap |= capital[v];
    ans.nodes++;
    ans.edges += g[v].size();

    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to, ans);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int k;
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < k; i++) {
        int v;
        scanf("%d", &v);
        capital[v] = true;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector <Comp> vec;
    int num = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            Comp temp{false, 0, 0, num++};
            dfs(i, temp);
            temp.edges /= 2;
            vec.emplace_back(temp);
        }
    }

    Comp mx = {false, -1, -1, -1};
    for (const auto& p : vec) {
        if (p.hasCap && p.edges > mx.edges) {
            mx = p;
        }
    }

    int nodesMax = mx.nodes;
    int edgesMax = mx.edges;
    int ans = 0;

    for (const auto& p : vec) {
        if (p.num == mx.num) {
            continue;
        }
        if (p.hasCap) {
            ans += f(p.nodes) - p.edges;
        } else {
            nodesMax += p.nodes;
            edgesMax += p.edges;
        }
    }

    ans += f(nodesMax) - edgesMax;

    printf("%d\n", ans);

    return 0;
}
