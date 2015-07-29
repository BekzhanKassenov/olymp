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
const int LG = 20;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, m, x, y, anc[maxn][LG], tin[maxn], tout[maxn], timer, depth[maxn];
vector <int> g[maxn];

void dfs(int v, int pr = 0, int gl = 0) {
    anc[v][0] = pr;
    tin[v] = timer++;
    depth[v] = gl;
    
    for (int i = 1; i < LG; i++)
        anc[v][i] = anc[anc[v][i - 1]][i - 1];
        
    for (size_t i = 0; i < g[v].size(); i++)
        if (g[v][i] != pr)
            dfs(g[v][i], v, gl + 1);
            
    tout[v] = timer++;
}

bool ancestor(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int get(int l, int r) {
    if (!ancestor(l, r))
        return anc[l][0] + 1;
        
    int ans = r;
    
    for (int i = LG - 1; i >= 0; i--) {
        if (depth[anc[ans][i]] > depth[l])
            ans = anc[ans][i];
    }
    
    return ans + 1;
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
