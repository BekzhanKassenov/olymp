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
const int maxn = 1010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

struct st {
    int l, r;
    int num, sz;
    
    st() { }
    
    st(int num) : l(0), r(0), num(num), sz(0) { }
    
    bool operator < (const st& str) const {
        return min(l, r) < min(str.l, str.r);
    }
};

multiset <st> Set;
int n, m, x, cnt[3];
vector <int> ans[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &x);
            
            if (x == 11)
                cnt[0]++;
            else if (x == 10 || x == 1)
                cnt[1]++;
            else
                cnt[2]++;
        }
    }  
    
    for (int j = 0; j < m; j++) {
        Set.insert(st(j));
        ans[j].reserve(n);
    }
    
    for (int i = 0; i < cnt[0]; i++) {
        st cur = *Set.begin();
        Set.erase(Set.begin());
        
        cur.l++;
        cur.r++;
        ans[cur.num].push_back(11);
        cur.sz++;
        
        if (cur.sz < n)
            Set.insert(cur);
    }
    
    for (int i = 0; i < cnt[1]; i++) {
        st cur = *Set.begin();
        Set.erase(Set.begin());
        
        if (cur.l < cur.r) {
            cur.l++;
            ans[cur.num].push_back(10);
        } else {
            cur.r++;
            ans[cur.num].push_back(1);
        }
        cur.sz++;
        
        if (cur.sz < n)
            Set.insert(cur);
    }
    
    for (int i = 0; i < cnt[2]; i++) {
        st cur = *Set.begin();
        Set.erase(Set.begin());
        
        cur.sz++;
        
        ans[cur.num].push_back(0);
        
        if (cur.sz < n)
            Set.insert(cur);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%02d ", ans[j][i]);
            
        printf("\n");
    }
    
    return 0;
}
