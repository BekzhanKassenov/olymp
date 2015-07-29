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

ll sqr(int n) {
    return n * 1ll * n;
}

const int size = 5e5 + 3;

struct my_set {
    vector <pair <int, int> > vec[size];
    
    void add(const pair <int, int>& p) {
        vec[(p.F * 31 + p.S) % size].push_back(p);
    }
    
    bool has(const pair <int, int>& p) {
        int h = (p.F * 31 + p.S) % size;
        
        for (size_t i = 0; i < vec[h].size(); i++) {
            if (vec[h][i] == p)
                return true;
        }
        
        return false;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    for (int n = 0; n <= 20; n++) {
    if (n == 0) {
        cout << 1 << ", ";
        continue;
    }
    
    
    
    my_set s;
    
    int ans = 0;
    
    for (int x = 1; x < n; x++) {
        int y = sqrt(sqr(n) - sqr(x));
        
        if (!s.has(MP(x, y))) {// && !s.has(MP(x - 1, y)) && !s.has(MP(x, y - 1)) && !s.has(MP(x + 1, y)) && !s.has(MP(x, y + 1))) {
            s.add(MP(x, y));
            ans++;
        }
        
        if (!s.has(MP(y, x))) {// && !s.has(MP(y - 1, x)) && !s.has(MP(y, x - 1)) && !s.has(MP(y + 1, x)) && !s.has(MP(y, x + 1))) {
            s.add(MP(y, x));
            ans++;
        }
    }
    
    ans++;
    
    cout << ans << ", ";}
    
    
    return 0;
}
