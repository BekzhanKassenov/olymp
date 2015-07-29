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
#define File "umbrellas"

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

int n, m;
int b[maxn], g[maxn];

int main() {
#ifndef ONLINE_JUDGE    
    freopen("in", "r", stdin);
#endif
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        cin >> g[i];
        
    for (int i = 0; i < m; i++)
        cin >> b[i];
        
    sort(g, g + n);
    sort(b, b + m);
    
    reverse(g, g + n);
    reverse(b, b + m);
    
    ll ans = 0;
    
    if (n > m) {
        for (int i = m; i < n; i++)
            ans += g[i];
    } else {
        ll k = n;
        ll sum = 0;
        ll sum1 = 0;
        
        for (int i = n; i < m; i++)
            sum += b[i];
            
        ans = k * sum;
        
        for (int i = n - 1; i >= 0; i--) {
            sum1 += g[i];
            sum += b[i];
            k--;
            
            ans = min(ans, sum1 + sum * k);
        }
    }
    
    cout << ans;
    
    return 0;
}
