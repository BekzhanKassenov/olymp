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
    int ini;
public:
    SegmentTree() : size(0) { }
    
    SegmentTree(int size) : size(size) { 
        t = new PII[4 * size * sizeof(int)];
        ini = 1;
        while (ini < size)
            ini *= 2;
        for (int i = 0; i < size; ++i)
            t[ini+i].S = i;
        for (int i = size; i < 4*size; ++i)
            t[ini+i].F = INF;
        for (int i = 0; i < size; i++)
            update(i, 0);   
    }
    
    void update(int pos, int num) {
        int v = pos + ini;
        t[v].F += num;
        while (v > 0){
            v /= 2;
            if (t[v*2].F > t[v*2+1].F)
                t[v] = t[v*2+1];
            else
                t[v] = t[v*2];   
        }
    }
    void print(){
        for (int i = 1; i < size + ini; ++i){
            cout << t[i].F << " ";
        }
        cout << endl;
    }
    PII get(int l, int r) {
        l += ini;
        r += ini;
        PII ans = t[l];
        while (l < r){
            if (l&1){
                if (ans.F > t[l].F)
                    ans = t[l];
                    l++;
            }
            else {
                if (ans.F > t[l].F)
                    ans = t[l];
            }
            if (!(r&1)){
                if (ans.F > t[r].F)
                    ans = t[r];
                r--;
            }
            else {
                if (ans.F > t[r].F)
                    ans = t[r];
            }
            l = (l>>1);
            r = (r>>1);        
        }
        if (l == r){
            if (ans.F > t[l].F)
                ans = t[l];
        }
        return ans;
    }
};

long long recurs(int l, int r, SegmentTree &tre){
    if (l > r)
        return 0;
    long long ans = 0;
    long long lx, rx, w;
    PII tp = tre.get(l, r);
//    cerr << tp.F << endl;
    w = (long long)tp.F;
    lx = (long long)tp.S - l;
    rx = (long long)r - tp.S;
    ans += (rx+1ll)*(lx+1ll)*w;
    ans += recurs(l, tp.S-1, tre) + recurs(tp.S+1, r, tre);
//    cerr << l << " " << r << endl;
  //  cerr << ans << endl;
    return ans;
}

char c[3001][3001];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    int n, m;
    scanf("%d%d\n", &n, &m);
    SegmentTree tre(m);    
    for (int i = 0; i < n; ++i){
        scanf("\n%s", c[i]);
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
