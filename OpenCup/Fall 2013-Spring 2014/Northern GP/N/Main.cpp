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
#define File "nfs"

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

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, y, b, s;
        cin >> n >> y >> b >> s;
        s--;
        
        VI a(n);
        
        int pos = 0;
        
        while (b) {
            for (int i = 0; i < y; i++) {
                if (i == s)
                    a[pos]++;
                    
                pos++;
                pos %= n;
            }
            b--;
        }
        
        int mx = 0;
        
        for (int i = 0; i < n; i++)
            mx = max(mx, a[i]);
            
        int cntmx = 0;
        
        for (int i = 0; i < n; i++)
            if (a[i] == mx)
                cntmx++;
                
        if (cntmx > 1) {
            int ans = 0;
            for (int i = 0; i < n; i++)
                if (a[i] == mx)
                    ans = i;
                    
            cout << ans + 1 << endl;
        } else {
            int mx2 = 0;
            
            for (int i = 0; i < n; i++)
                if (a[i] != mx)
                    mx2 = max(a[i], mx2);
                    
            int ans = 0;
            
            for (int i = 0; i < n; i++)
                if (a[i] == mx2)
                    ans = i;
                    
            cout << ans + 1 << endl;
        }
    }
    
    return 0;
}
