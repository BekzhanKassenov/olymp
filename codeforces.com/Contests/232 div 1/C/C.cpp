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
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 300110;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, x, timer, tin[maxn], tout[maxn], depth[maxn];
int m, t, ver, k;
ll tree[maxn], flag_a[4 * maxn], flag_b[4 * maxn];
vector <int> g[maxn];

void dfs(int v, int dpth = 0) {
    tin[v] = ++timer;
    depth[tin[v]] = dpth;
    
    for (size_t i = 0; i < g[v].size(); i++) {
        dfs(g[v][i], dpth + 1);
    }
    
    tout[v] = timer;
}

void push(int v, int l, int r) {
    if (l > r)
        return;
        
    if (l == r) {
        tree[l] += ((flag_a[v] - depth[l] * 1ll * flag_b[v]) % MOD + MOD) % MOD;
        tree[l] %= MOD;
    } else {
    
        flag_a[v << 1] += flag_a[v];
        flag_b[v << 1] += flag_b[v];
        
        flag_a[(v << 1) + 1] += flag_a[v];
        flag_b[(v << 1) + 1] += flag_b[v];
        
        flag_a[v << 1] %= MOD;
        flag_b[v << 1] %= MOD;
        
        flag_a[(v << 1) + 1] %= MOD;
        flag_b[(v << 1) + 1] %= MOD;
    }
    
    flag_a[v] = 0;
    flag_b[v] = 0;
}

void update(int v, int l, int r, int q_l, int q_r, ll fla, ll flb) {
    push(v, l, r);
    
    if (l > r || q_l > r || q_r < l)
        return;
        
    if (q_l <= l && r <= q_r) {
        flag_a[v] += fla;
        flag_b[v] += flb;
        push(v, l, r);
        return;
    }
    
    int mid = (l + r) >> 1;
    
    update( v << 1,      l,       mid, q_l, q_r, fla, flb);
    update((v << 1) + 1, mid + 1, r,   q_l, q_r, fla, flb);
}

ll get(int v, int l, int r, int pos) {
    push(v, l, r);
    
    if (l > r || pos < l || pos > r)
        return 0;
        
    if (l == r)
        return tree[l];
        
    int mid = (l + r) >> 1;
    
    return get(v << 1, l, mid, pos) + get((v << 1) + 1, mid + 1, r, pos);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    
    for (int i = 1; i < n; i++) {
        scanf("%d", &x);
        g[--x].push_back(i);
    }
    
    dfs(0);
    
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d%d", &ver, &x, &k);
            
            ver--;
            
            ll fla = (x + depth[tin[ver]] * 1ll * k) % MOD;
            ll flb = k;
            
            update(1, 1, n, tin[ver], tout[ver], fla, flb);
        } else {
            scanf("%d", &ver);
            printf("%I64d\n", get(1, 1, n, tin[--ver]));
        }
    }

    return 0;
}
