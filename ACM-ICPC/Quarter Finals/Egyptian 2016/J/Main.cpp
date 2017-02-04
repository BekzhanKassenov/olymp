/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "car"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 500010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
vector <pair <int, int> > g[MAXN];
int X[MAXN];
long long depth[MAXN];

struct SetComp {
    bool operator() (int a, int b) const {
        long long vala = depth[a] - X[a];
        long long valb = depth[b] - X[b];

        if (vala != valb) {
            return vala > valb;
        }

        return a < b;
    }
};

set <int, SetComp> vals[MAXN];
int ans[MAXN];

void dfs(int v, int par = 0) {
    int biggest = -1;
    for (const auto& edge : g[v]) {
        int to = edge.first;
        if (to != par) {
            depth[to] = depth[v] + edge.second;
            dfs(to, v);
            if (biggest == -1 || vals[to].size() > vals[biggest].size()) {
                biggest = to;
            }
        }
    }

    if (biggest != -1) {
        vals[v].swap(vals[biggest]);
    }

    for (const auto& edge : g[v]) {
        int to = edge.first;
        if (to != par && to != biggest) {
            for (int ver : vals[to]) {
                if (depth[ver] - X[ver] <= depth[v]) {
                    vals[v].insert(ver);
                }
            }
        }
    }

    while (!vals[v].empty()) {
        int ver = *vals[v].begin();
        if (depth[ver] - X[ver] > depth[v]) {
            vals[v].erase(vals[v].begin());
        } else {
            break;
        }
    }

    ans[v] = vals[v].size();
    vals[v].insert(v);
}

int main() {
    freopen(File".in", "r", stdin);
    
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            g[i].clear();
            vals[i].clear();
        }

        for (int i = 1; i <= n; i++) {
            scanf("%d", &X[i]);
        }

        for (int i = 0; i < n - 1; i++) {
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            g[u].emplace_back(v, c);
            g[v].emplace_back(u, c);
        }

        dfs(1);

        for (int i = 1; i <= n; i++) {
            printf("%d%c", ans[i], " \n"[i == n]);
        }
    }

    return 0;
}
