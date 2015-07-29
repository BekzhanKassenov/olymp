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
#define File "letter"

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

ll fact(int n) {
    if (!n)
        return 1;
        
    return n * 1ll * fact(n - 1);
}

bool used[100500];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    int n;
    ll m;
    
    cin >> n >> m;
    
    m--;
    
    vector <string> a(n);
    
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    
    sort(all(a));
    
    vector <int> ans;
    
    for (int i = n - 1; i >= 0; i--) {
        int k = m / fact(i);
        int j, r;
        
        for (j = 0, r = 0; j < n; j++) {
            if (!used[j])
                r++;
            if (r == k + 1)
                break;
        }
        
        used[j] = true;
        ans.push_back(j + 1);
        
        m %= fact(i);
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ' ;
    }
    
    return 0;
}
