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
const int MAXN = 510;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Edge {
    int to;
    int flow, cap;
};

Edge e[2000];
int lastE;
vector <int> g[MAXN];
int S = 0, T = MAXN - 1;
int level[MAXN];
bool used[MAXN];

void add_edge(int from, int to, int cap) {
    e[lastE] = Edge{to, 0, cap};
    g[from].push_back(lastE);
    lastE++;

    e[lastE] = Edge{from, 0, 0};
    g[to].push_back(lastE);
    lastE++;
}

bool dfs(int v, int T, int cur_flow) {
    if (used[v]) {
        return false;
    }

    used[v] = true;
    if (v == T) {
        return true;
    }

    for (size_t i = 0; i < g[v].size(); i++) {
        int idx = g[v][i];
        int to = e[idx].to;

        if (e[idx].cap - e[idx].flow >= cur_flow && dfs(to, T, cur_flow)) {

            e[idx].flow += cur_flow;
            e[idx ^ 1].flow -= cur_flow;
            return true;
        }
    }

    return false;
}

void runflow() {
    int cur_flow = 1024;

    while (cur_flow > 0) {
        memset(used, false, sizeof used);
        if (!dfs(S, T, cur_flow)) {
            cur_flow >>= 1;
        }
    }
}

int a[MAXN], b[MAXN];
int n, m, x, y;
int ans[MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }

    for (int i = 1; i <= n; i++) {
        add_edge(S, i, a[i]);
        add_edge(i + n, T, b[i]);
        add_edge(i, i + n, INF);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        
        add_edge(x, y + n, INF);
        add_edge(y, x + n, INF);
    }

    runflow();

    for (size_t i = 0; i < g[S].size(); i++) {
        int idx = g[S][i];
        if (e[idx].flow != e[idx].cap) {
            puts("NO");
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (size_t j = 0; j < g[i + n].size(); j++) {
            int idx = g[i + n][j];

            if (e[idx].to == T && e[idx].flow != e[idx].cap) {
                puts("NO");
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (size_t j = 0; j < g[i].size(); j++) {
            int idx = g[i][j];
            if (e[idx].to > n) {
                ans[i][e[idx].to - n] = e[idx].flow;
            }
        }
    }

    puts("YES");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d%c", ans[i][j], " \n"[j == n]);
        }
    }

    return 0;
}