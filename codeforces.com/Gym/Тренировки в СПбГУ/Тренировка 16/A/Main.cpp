/****************************************
**          Solution by NU #2          **
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
const int MAXN = 20010;
const int MAXM = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, x, y, ans;
pair <int, int> e[MAXM];
vector <int> g[MAXN];
bool bridge[MAXM];
int tin[MAXN], fup[MAXN], timer;
bool used[MAXN];
map <pair <int, int>, int> edges;

void dfs(int v, int par = -1) {
    tin[v] = fup[v] = timer++;
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); i++) {
        int to = e[g[v][i]].first + e[g[v][i]].second - v;

        if (to == par)
            continue;

        if (!used[to]) {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);

            if (fup[to] > tin[v] && edges[e[g[v][i]]] == 1) {
                bridge[g[v][i]] = true;
                ans++;
            }
        } else {
            fup[v] = min(fup[v], tin[to]);
        }
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &e[i].first, &e[i].second);
        g[e[i].first].push_back(i);
        g[e[i].second].push_back(i);

        if (e[i].first > e[i].second)
            swap(e[i].first, e[i].second);

        edges[e[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }

    printf("%d\n", ans);
    for (int i = 1; i <= m; i++) {
        if (bridge[i]) {
            printf("%d ", i);
        }
    }
    
    return 0;
}
