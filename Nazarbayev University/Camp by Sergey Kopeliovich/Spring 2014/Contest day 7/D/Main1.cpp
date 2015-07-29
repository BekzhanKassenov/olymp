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
#define File "rect"

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
    PII *t;
    int size;
    
public:
    SegmentTree() : size(0) { }
    
    SegmentTree(int size) : size(size) { 
        t = new PII[4 * size * sizeof(int)];
        
        for (int i = 0; i < size; i++)
            update(i, 0);   
    }
    
    void update(int pos, int num) {
        update(1, 0, size - 1, pos, num);
    }
    
    PII get(int l, int r) {
        return get(1, 0, size - 1, l, r);
    }
    
private:
    void update(int v, int l, int r, int pos, int num) {
        if (l > r || pos < l || pos > r)
            return;
            
        if (l == r) {
            t[v].F += num;
            t[v].S = l;
            cerr << v << ' ' << l << ' ' << r << ' ' << t[v].F << ' ' << t[v].S << endl;
            return;
        }
        
        int mid = (l + r) >> 1;
        
        update(v << 1, l, mid, pos, num);
        update((v << 1), mid + 1, r, pos, num);
        
        t[v] = combine(t[v << 1], t[(v << 1) + 1]);
    }
    
    PII get(int v, int l, int r, int q_l, int q_r) {
        if (l > r || q_r < l || r < q_l)
            return MP(INF, -1);
            
        if (q_l <= l && r <= q_r)
            return t[v];
            
        int mid = (l + r) >> 1;
        
        return combine(get(v << 1, l, mid, q_l, q_r), get((v << 1) + 1, mid + 1, r, q_l, q_r));
    }
    
    PII combine(const PII& f, const PII& s) {
        if (f.F < s.F)
            return f;
            
        return s;
    }
};

long long recurs(int l, int r, SegmentTree &tre){
    if (l > r)
        return 0;
    //cerr << l << " " << r << endl;
    long long ans = 0;
    long long lx, rx, w;
    PII tp = tre.get(l, r);
    //cerr << tp.S << endl;
    w = (long long)tp.F;
    lx = (long long)tp.S;
    rx = (long long)r - tp.S;
    ans += (rx+1ll)*(lx+1ll)*w;
    ans += recurs(l, tp.S-1, tre) + recurs(tp.S+1, r, tre);
    return ans;
}

char c[3001][3001];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    SegmentTree tre(m);    
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j)
            cin >> c[i][j];
    }
    
    long long ans = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (c[i][j] == 'B'){
                tre.update(j, -tre.get(j, j).F);
            }
            else {
                tre.update(j, 1);
            }
        }
        ans += recurs(0, m-1, tre);
    }
    cout << ans;
    return 0;
}
