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
#define File "frontier"

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
const int maxn = 50010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

class SegmentTree {
    int *t;
    int size;
    
public:
    SegmentTree() : size(0) { }
    
    SegmentTree(int size) : size(size) {
        t = new int[4 * sizeof(int) * size];
        memset(t, false, sizeof (int) * size * 4); 
    }
    
    void update(int l, int r) {
        if (l > r)
            swap(l, r);
            
        update(1, 0, size - 1, l, r);
    }
    
    int painted(int pos) {
        return painted(1, 0, size - 1, pos);
    }
  
private:
    void update(int v, int l, int r, int q_l, int q_r) {
        if (l > r || q_r < l || r < q_l)
            return;

        //cerr << v << ' ' << l << ' ' << r << ' ' << q_l << ' ' << q_r << ' ' << t[v] << endl;

        if (q_l <= l && r <= q_r) {
            t[v] = true;
            return;
        }
        
        int mid = (l + r) >> 1;
        
        update(v << 1, l, mid, q_l, q_r);
        update((v << 1) + 1, mid + 1, r, q_l, q_r);
    }
    
    int painted(int v, int l, int r, int pos) {
        if (l > r || pos < l || pos > r)
            return false;
            
        //cerr << v << ' ' << l << ' ' << r << ' ' << t[v] << endl;
            
        if (l == r) 
            return t[v];
            
        int mid = (l + r) >> 1;
        
        return t[v] || painted(v << 1, l, mid, pos) || painted((v << 1) + 1, mid + 1, r, pos);
    }
};

int n, a[maxn];
SegmentTree tree[2];

void compress() {
    map <int, int> Map;
    vector <int> temp;
    
    for (int i = 0; i < n; i++) {
        temp.push_back(a[i]);
    }
    
    sort(all(temp));
    
    temp.resize(unique(all(temp)) - temp.begin());
    
    if ((int)temp.size() < n) {
        cout << "YES";
        exit(0);
    }
    
    for (int i = 0; i < n; i++) {
        Map[temp[i]] = i;
    }
    
    for (int i = 0; i < n; i++)
        a[i] = Map[a[i]];
        
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    
    compress();
    
    tree[0] = SegmentTree(n + 1);
    tree[1] = SegmentTree(n + 1);
    
    bool cur = 0;
    
    for (int i = 0; i < n - 1; i++) {
        
        int l = a[i], r = a[i + 1];
        
        if (l > r)
            swap(l, r);
        
        if (tree[cur].painted(l) || tree[cur].painted(r)) {
            cout << "YES";
            cerr << i << endl;
            return 0;
        } else {
            tree[cur].update(l, r);
        }

        cur ^= 1;
    }
    
    cout << "NO";
    return 0;
}
