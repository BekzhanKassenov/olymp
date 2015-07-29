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
#define File "elves"

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
const int maxn = 110;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

struct triple {
    int le, re, h;

    triple() { }

    triple(int le, int re, int h) : re(re), le(le), h(h) { } 
    
    bool operator < (const triple& rhs) const {
        if (re != rhs.re)
            return re < rhs.re;
            
        if (le != lhs.le)
            return le < rhs.le;
            
        return h < rhs.h;
    }
};

vector <pair <int, bool> > v;
multiset <int> afree, bfree;
set <triple> answer;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    int n, m;
    
    scanf("%d%d", &m, &n); 
    
    for (int i = 0; i < m; ++i){
        int x;
        scanf("%d", &x);
        v.push_back(MP(x, 1));
    }
    
    for (int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        v.push_back(MP(x, 0));
    }
    
    sort(v.begin(), v.end());
    
    for (int i = 0; i < v.size(); ++i){
        if (v[i].second){
            bfree.insert(v[i].F);
        } else {
            if (!bfree.empty()) {
                multiset <int> :: iterator new_b = bfree.lower_bound(v[i].F - 1);
                
                if (new_b == bfree.end()) {
                    afree.insert(v[i].F);
                } else {
                    multiset <int> :: iterator new_a = afree.lower_bound(*new_b - 1);
                    
                    if (new_a == afree.end()) {
                        
                    }
                }
            } else {
            }
        }
    }
    return 0;
}
