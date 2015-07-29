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
int ans[maxn];
vector <int> g[maxn];
vector <pair <int, int> > query[maxn];
map <int, vector <int> > Map;

void dfs(int v, int pr = -1) {
    tin[v] = ++timer;
    par[v] = pr;
    
    for (size_t i = 0; i < g[v].size(); i++) {
        if (g[v][i] != pr) {
            dfs(g[v][i], v);
        }
    }
    
    tout[v] = ++timer;
}

bool ancestor(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

void dfs2(int v, int pr = 0) {
    for (size_t i = 0; i < query[v].size(); i++)
        Map[query[v][i].F].push_back(query[v][i].S);
        
    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        
        if (to == pr)
            continue;
            
        dfs2(to, v);
        
        for (size_t i = 0; i < Map[v].size(); i++)
            ans[Map[v][i]] = to + 1;
            
        Map[v].clear();
    }
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
        
        x--, y--;
        
        if (!ancestor(x, y))
            ans[i] = par[x] + 1;
        else
            query[y].push_back(MP(x, i));
    }
    
    dfs2(0);
    
    for (int i = 0; i < m; i++)
        printf("%d\n", ans[i]);
    
    return 0;
}
