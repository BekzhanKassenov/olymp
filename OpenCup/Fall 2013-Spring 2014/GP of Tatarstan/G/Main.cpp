/****************************************
**          Solution by NU #2          **
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
const int maxn = 100010;
const int LG = 21;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

vector <int> g[maxn];
int n, m, x, y;
int tin[maxn], tout[maxn], ancestor[maxn][LG], timer, depth[maxn];


class FenwickTree {
public:
    int *t, size;
    
    FenwickTree() : size(size) {
        t = new int[size];
        memset(t, 0, sizeof(int) * size);
    }
    
    void update(int pos) {
        for (int i = pos; i < size; i += i & (-i))
            t[i] ++;
    } 
    
    int get(int pos) {
        int res = 0;
        for (int i = pos; i >= 0; i -= i & (-i)) {
            res += t[i];
            if (i == 0)
                break;
        }
    }
    
    int get(int l, int r) {
        return get(r) - (l ? get(l - 1) : 0);
    }
};


void dfs(int v, int pr = 0, int gl = 0) {
    ancestor[v][0] = pr;
    tin[v] = ++timer;
    depth[v] = gl;
    
    for (int i = 1; i < LG; i++)
        ancestor[v][i] = ancestor[ancestor[v][i - 1]][i - 1];
        
    for (size_t i = 0; i < g[v].size(); i++)
        if (g[v][i] != pr)
            dfs(g[v][i], v, gl + 1);
    
    tout[v] = timer;
}

SegmentTree *pred, *ans;

int get_pred(int v) {
    for (int i = LG - 1; i >= 0; i--) {
        int parent = ancestor[v][i];
        if (!(pred -> sum(tin[parent], tout[parent])))
            v = parent;
    }
    
    return ancestor[v][0];
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &n);
    
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &x, &y);
        
        g[--x].push_back(--y);
        g[y].push_back(x);
    }
    
    dfs(0);
    ans = new SegmentTree(depth, n);
    pred = new SegmentTree(n);
    
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        x--;
        
        int res = ans -> get(tin[x]);
        
        if (!(pred -> sum(tin[x], tout[x]))) {
            int par = get_pred(x);
            int diff = depth[x] - depth[par];
            
            ans -> update(0, tin[x] - 1, diff);
            ans -> update(0, tout[x] + 1, diff);
            
            ans -> update(tin[x], tout[x], -ans -> get(tin[x], tout[x]) + depth[x] + ans -> get(tin[x])
        }
    }
    
    return 0;
}

