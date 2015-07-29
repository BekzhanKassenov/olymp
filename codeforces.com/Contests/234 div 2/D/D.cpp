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

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 100010;
const int maxk = 510;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, m, k, c[maxk], comp[maxn], u, v, x, comp_num;
ll d[maxk][maxk];
vector <int> g[maxn];

int get_pos(int nn) {
    return lower_bound(c + 1, c + k + 1, nn) - c;
}

void dfs(int v, int comp_num) {
    comp[v] = comp_num;
    
    for (size_t i = 0; i < g[v].size(); i++)
        if (!comp[g[v][i]])
            dfs(g[v][i], comp_num);
            
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    scanf("%d%d%d", &n, &m, &k);
    
    for (int i = 1; i <= k; i++)
        scanf("%d", &c[i]);
        
    for (int i = 1; i <= k; i++)
        c[i] += c[i - 1];
    
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= k; j++)
            d[i][j] = INF;
    
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &x);
        
        if (x == 0) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        int pos_u = get_pos(u);
        int pos_v = get_pos(v);
        
        d[pos_u][pos_v] = min(d[pos_u][pos_v], x * 1ll);
        d[pos_v][pos_u] = min(d[pos_v][pos_u], x * 1ll);
    }
    
    for (int i = 1; i <= n; i++)
        if (!comp[i])
            dfs(i, ++comp_num);
            
    for (int i = 1; i <= k; i++) {
        int first = c[i - 1] + 1;
        
        for (int j = c[i - 1] + 1; j <= c[i]; j++) {
            if (comp[j] != comp[first]) {
                puts("No");
                return 0;
            }
        }
    }    
    
    for (int i = 1; i <= k; i++)
        d[i][i] = 0;
        
    for (int l = 1; l <= k; l++) {
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= k; j++) {
                d[i][j] = min(d[i][j], d[i][l] + d[l][j]);
            }
        }
    }
        
    puts("Yes");
    
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++)
            if (d[i][j] != INF)
                printf("%I64d ", d[i][j]);
            else
                printf("-1 ");
            
        puts("");
    }
    
    return 0;
}
