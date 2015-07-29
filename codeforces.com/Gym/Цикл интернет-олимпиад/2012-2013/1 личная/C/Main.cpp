/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "canalisation"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, m, x, y, tin[maxn], tout[maxn], par[maxn], timer;
vector <int> g[maxn], g_tout[maxn], g_child[maxn];

void dfs(int v, int pr = -1) {
    tin[v] = ++timer;
    par[v] = pr;
    
    for (size_t i = 0; i < g[v].size(); i++) {
        if (g[v][i] != pr) {
            dfs(g[v][i], v);
            g_tout[v].push_back(timer);
            g_child[v].push_back(g[v][i]);
        }
    }
    
    tout[v] = ++timer;
}

bool ancestor(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int get(int l, int r) {
    if (!ancestor(l, r))
        return par[l] + 1;
        
    int pos = lower_bound(all(g_tout[l]), tout[r]) - g_tout[l].begin();
    
    return g_child[l][pos] + 1;
}   

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &x, &y);
        
        g[--x].push_back(--y);
        g[y].push_back(x);
    }
    
    dfs(0);
    
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        
        printf("%d\n", get(--x, --y));
    }
    
    return 0;
}
