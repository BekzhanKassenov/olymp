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
#define File "pizza"

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
const int maxn = 1000010;
const int LG = 21;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

class SegmentTree {
public:
    SegmentTree() { }
    
    SegmentTree(int size) : size(size) { 
        tree = new ll[4 * size];
        memset(tree, 0, 4 * size * sizeof (ll));
    }
    
    void update(int l, int r, ll val) {
        update(1, 0, size - 1, l, r, val);
    }
    
    ll get(int pos) {
        return get(1, 0, size - 1, pos);
    }
    
private:
    void update(int v, int l, int r, int q_l, int q_r, ll val) {
        if (l > r || q_l > r || q_r < l)
            return;
            
        if (q_l <= l && r <= q_r)
            tree[v] += val;
        else {
            int mid = (l + r) >> 1;
            
            update(v << 1, l, mid, q_l, q_r, val);
            update((v << 1) + 1, mid + 1, r, q_l, q_r, val);
        }
    }
    
    ll get(int v, int l, int r, int pos) {
        if (l > r || pos < l || pos > r)
            return 0;
            
        if (l == r)
            return tree[v];
            
        int mid = (l + r) >> 1;
        
        return tree[v] + 
               get(v << 1, l, mid, pos) + 
               get((v << 1) + 1, mid + 1, r, pos);
    }
    
    ll *tree;
    int size;
};

int n, m, tin[maxn], tout[maxn], timer, cost[maxn], depth[maxn];
int leaf_number[maxn], x, y, g[maxn][26], last = 1;
int ancestor[maxn][LG];
char s[maxn], c;

int add_string(char s[]) {
    int cur = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (g[cur][s[i] - 'a'] == -1) {
            g[cur][s[i] - 'a'] = last++;
        }
        
        cur = g[cur][s[i] - 'a'];
    }
    
    return cur;
}

void dfs(int v, int pr = 0, int gl = 0) {
    tin[v] = ++timer;
    ancestor[v][0] = pr;
    depth[v] = gl;
    
    for (int i = 1; i < LG; i++)
        ancestor[v][i] = ancestor[ancestor[v][i - 1]][i - 1];
        
    for (int i = 0; i < 26; i++) {
        if (g[v][i] != -1)
            dfs(g[v][i], v, gl + 1);
    }
    
    tout[v] = timer;
}

int get_ancestor(int v, int num) {
    int ans = v;
    
    for (int i = LG - 1; i >= 0; i--) {
        if (depth[ancestor[ans][i]] > num)
            ans = ancestor[ans][i];
    }
    
    return ancestor[ans][0];
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    memset(g, 255, sizeof g);
    
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < n; i++) {
        scanf("%s%d", s, cost + i);
        
        leaf_number[i] = add_string(s);
    }
    
    dfs(0);
    
    SegmentTree tree(timer + 1);
    
    for (int i = 0; i < n; i++) {
        tree.update(tin[leaf_number[i]], tout[leaf_number[i]], cost[i]);
    }
    
    for (int i = 0; i < m; i++) {
        scanf("\n%c%d%d", &c, &x, &y);
        x--;
        
        if (c == '?') {
            int h = get_ancestor(leaf_number[x], y - 1);
            
            if (y > depth[leaf_number[x]])
                puts("0");
            else {
                printf("%I64d\n", tree.get(tin[leaf_number[x]]) - tree.get(tin[h]));
            }
        } else {
            tree.update(tin[leaf_number[x]], tout[leaf_number[x]], y);
        }
    }
    
    return 0;
}
