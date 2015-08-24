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
const int MAXM = 2 * MAXN;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

// Edges
int to[2 * MAXM], cost[2 * MAXM];
bool bridge[2 * MAXM];
int lastEdge;

int n, m, T;
int tin[MAXN], fup[MAXN], timer;
int block[MAXN];
int x, y, c;

// DP
long long innerDP[MAXN], outerDP[MAXN];
long long dp[MAXN];

bool used[MAXN];
vector <int> g[MAXN];
vector <int> tree[MAXN];

inline void cleanVars() {
    memset(used, false, sizeof(bool) * (n + 1));
    memset(block, 255, sizeof(int) * (n + 1));
    memset(innerDP, 0, sizeof(long long) * (n + 1));
    memset(outerDP, 0, sizeof(long long) * (n + 1));
    memset(dp, 0, sizeof(long long) * (n + 1));

    for (int i = 0; i <= n; ++i) {
        g[i].clear();
        tree[i].clear();
    }

    timer = 0;
    lastEdge = 0;
}

inline void initEdge(int t, int c, bool b) {
    to[lastEdge] = t;
    cost[lastEdge] = c;
    bridge[lastEdge] = b;
}

inline void dfsBridge(int v, int par = -1) {
    used[v] = true;
    tin[v] = fup[v] = ++timer;

    for (size_t i = 0; i < g[v].size(); ++i) {
        int _to = to[g[v][i]];
        if (_to == par) {
            continue;
        }

        if (!used[_to]) {
            dfsBridge(_to, v);
            fup[v] = min(fup[v], fup[_to]);

            if (tin[v] < fup[_to]) {
                bridge[g[v][i]] = true;
            }
        } else {
            fup[v] = min(fup[v], tin[_to]);
        }
    }
}

inline void dfsBlock(int v, int bnum) {
    block[v] = bnum;

    for (size_t i = 0; i < g[v].size(); ++i) {
        int idx = g[v][i];
        if (!bridge[idx] && block[to[idx]] == -1) {
            dfsBlock(to[idx], bnum);
        }
    }
}

inline void dfsInnerDP(int v, int par = -1) {
    for (size_t i = 0; i < tree[v].size(); ++i) {
        if (to[tree[v][i]] == par) {
            swap(tree[v][i], tree[v].back());
            tree[v].pop_back();
            break;
        }
    }

    for (size_t i = 0; i < tree[v].size(); ++i) {
        int idx = tree[v][i];
        dfsInnerDP(to[idx], v);
        innerDP[v] = max(innerDP[v], cost[idx] + innerDP[to[idx]]);
    }
}

#define f(x) (innerDP[to[tree[v][x]]] + cost[tree[v][x]])

inline void dfsOuterDP(int v) {
    if (tree[v].empty()) {
        return;
    }

    if (tree[v].size() == 1) {
        int idx = tree[v][0];    
        outerDP[to[idx]] = outerDP[v] + cost[idx];
        dfsOuterDP(to[idx]);
    } else {
        // Searching for two maximums
        int mx1 = 0, mx2 = 1;
        if (f(1) > f(0)) {
            mx1 = 1, mx2 = 0;
        }

        for (size_t i = 2; i < tree[v].size(); ++i) {
            if (f(i) > f(mx1)) {
                mx2 = mx1;
                mx1 = i;
            } else if (f(i) > f(mx2)) {
                mx2 = i;
            }
        }

        // Calc outerDP
        for (size_t i = 0; i < tree[v].size(); ++i) {
            int idx = tree[v][i];
            int mx = mx1;
            if ((int)i == mx1) {
                mx = mx2;
            }

            outerDP[to[idx]] = max(f(mx), outerDP[v]) + cost[idx];
        }

        // Recursive call
        for (size_t i = 0; i < tree[v].size(); ++i) {  
            dfsOuterDP(to[tree[v][i]]);
        }
    }
}

stringstream ss;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m);
        cleanVars();

        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &x, &y, &c);
            
            initEdge(y, c, false);
            g[x].push_back(lastEdge++);
            
            initEdge(x, c, false);
            g[y].push_back(lastEdge++);
        }

        dfsBridge(1);

        int bnum = 0;
        for (int i = 1; i <= n; ++i) {
            if (block[i] == -1) {
                dfsBlock(i, bnum++);
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (size_t j = 0; j < g[i].size(); ++j) {
                int idx = g[i][j];
                
                if (bridge[idx]) {
                    initEdge(block[to[idx]], cost[idx], false);
                    tree[block[i]].push_back(lastEdge++);

                    initEdge(block[i], cost[idx], false);
                    tree[block[to[idx]]].push_back(lastEdge++);
                }
            }
        }

        dfsInnerDP(0);
        dfsOuterDP(0);
        
        for (int i = 0; i < bnum; ++i) {
            dp[i] = max(innerDP[i], outerDP[i]);
        }

        int ans = 0;
        for (int i = 1; i < bnum; ++i) {
            if (dp[i] < dp[ans]) {
                ans = i;
            }
        }

        int anscity = -1;
        for (int i = 1; i <= n; ++i) {
            if (dp[block[i]] == dp[ans]) {
                anscity = i;
                break;
            }
        }

        ss << anscity << ' ' << dp[ans] << endl;
    }

    cout << ss.str() << endl;

    return 0;
}
