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

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

class SegmentTree {
public:
    SegmentTree() { }
    
    SegmentTree(int size) : size(size) {
        flag = new ll[4 * size];
        sum = new ll[4 * size];
        
        for (int i = 0; i < 4 * size; i++) {
            flag[i] = 0;
            sum[i] = 0;
        }
    }
    
    void update(int l, int r, ll val) {
        update(1, 0, size - 1, l, r, val);
    }
    
    ll get(int l, int r) {
        return get(1, 0, size - 1, l, r);
    }
    
private:
    void push(int v, int l, int r) {
        if (l > r)
            return;
            
        if (l < r) {
            flag[v << 1]       += flag[v];
            flag[(v << 1) + 1] += flag[v];
        }
            
        sum[v] += (r - l + 1) * 1ll * flag[v];
        
        flag[v] = 0;
    }
    
    void update(int v, int l, int r, int q_l, int q_r, ll val) {
        push(v, l, r);
        
        if (l > r || q_l > r || q_r < l)
            return;
            
        if (q_l <= l && r <= q_r) {
            flag[v] += val; 
            push(v, l, r);
        } else {
            int mid = (l + r) >> 1;
            
            update( v << 1,      l,     mid, q_l, q_r, val);
            update((v << 1) + 1, mid + 1, r, q_l, q_r, val);
            
            sum[v] = sum[v << 1] + sum[(v << 1) + 1];
        }
    }
    
    ll get(int v, int l, int r, int q_l, int q_r) {
        push(v, l, r);
        
        if (l > r || q_l > r || q_r < l)
            return 0ll;
        
        if (q_l <= l && r <= q_r)
            return sum[v];
            
        int mid = (l + r) >> 1;
        return get( v << 1,      l,       mid, q_l, q_r) +
               get((v << 1) + 1, mid + 1, r,   q_l, q_r);
    }
    
    ll *sum, *flag;
    int size;
};

int n, m, w, t, x, y, _x, _y;
ll sum, val;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d", &n, &m);
    
    SegmentTree rows(n);
    SegmentTree colums(m);

    scanf("%d", &w);
    
    for (int i = 0; i < w; i++) {
        scanf("\n%d %d %d %d %d", &t, &x, &y, &_x, &_y);
        
        if (t == 0) {
            scanf("%I64d", &val);
            
            sum +=  (_y - y + 1) * 1ll * (_x - x + 1) * 1ll * val;
            
            rows.update  (x - 1, _x - 1, (_y - y + 1) * 1ll * val);
            colums.update(y - 1, _y - 1, (_x - x + 1) * 1ll * val);
        } else {
            ll res = rows.get(x - 1, _x - 1) + colums.get(y - 1, _y - 1) - sum;
            
            printf("%I64d\n", res);
        }
    }
    
    return 0;
}
