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

long long f(long long n) {
    return (n * (n - 1)) / 2;
}

int n, m;
vector <int> g[MAXN];
int cnum, csize[MAXN];
bool used[MAXN];
int comp[MAXN], bridges[MAXN];
int tin[MAXN], tout[MAXN];
int fup[MAXN], timer;

int subcomp[MAXN];
vector <pair <int, int> > bridgeList;

void dfs(int v, int c, int par = 0) {
    comp[v] = c;
    used[v] = true;
    csize[c]++;
    tin[v] = fup[v] = timer++;
    subcomp[v] = 1;
    
    for (int to: g[v]) {
        if (to == par) {
            continue;
        }
        
        if (!used[to]) {
            dfs(to, c, v);
            subcomp[v] += subcomp[to];
            fup[v] = min(fup[v], fup[to]);
            
            if (fup[to] > tin[v]) {
                bridges[c]++;
                bridgeList.emplace_back(v, to);
            }
        } else {
            fup[v] = min(fup[v], tin[to]);
        }
    }
    
    tout[v] = timer++;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i, cnum++);
        }
    }
    
    if (cnum > 2) {
        puts("0");
        return 0;
    }
    
    if (cnum == 2) {
        long long ans = csize[0];
        ans *= csize[1];
        ans *= m - (bridges[0] + bridges[1]);
        printf("%lld\n", ans);
        
        return 0;
    }
    
    long long ans = 0;
    for (const auto& p: bridgeList) {
        long long cntr = subcomp[p.second];
        long long cntl = n - cntr;
        ans += cntl * cntr - 1;
    }
    
    ans += (1ll * m - bridges[0]) * (f(n) - m);
    
    printf("%lld\n", ans);
    
    return 0;
}
