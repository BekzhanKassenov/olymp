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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n;
vector <pair <int, int> > edges[MAXN];
vector <long long> res;

void dfs(int v, long long T) {
    if (edges[v].empty()) {
        res.push_back(T);
        return;
    }

    int mn = INF;

    for (const auto& edge: edges[v]) {
        mn = min(mn, edge.second);
    }

    for (const auto& edge: edges[v]) {
        dfs(edge.first, T + mn + (edge.second - mn) * 2);
    }
}

void clear() {
    for (int i = 1; i <= n; i++) {
        edges[i].clear();
    }

    res.clear();
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        clear();

        for (int i = 2; i <= n; i++) {
            int par, cost;
            scanf("%d%d", &par, &cost);
            edges[par].emplace_back(i, cost);
        }

        dfs(1, 0);

        sort(all(res));

        int Q;
        scanf("%d", &Q);

        while (Q--) {
            long long t;
            scanf("%I64d", &t);

            printf("%d\n", upper_bound(all(res), t) - res.begin());
        }
    }
    
    return 0;
}
