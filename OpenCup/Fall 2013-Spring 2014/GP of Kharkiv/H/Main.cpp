/****************************************
**         Solution by NU #2           **
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
const int maxn = 201000;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, a[maxn], b[maxn], ans;
bool used[maxn];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
        
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
        
    sort(a, a + n);
    reverse(a, a + n);
    
    multiset <int> Set(b, b + n);
    
    for (int i = 0; i < n; i++) {
        multiset <int> :: iterator it = Set.upper_bound(a[i]);
        
        if (it != Set.end()) {
            ans += 2;
            Set.erase(it);
            used[i] = true;
        } 
    }
    
    for (int i = 0; i < n; i++) {
        if (used[i])
            continue;
            
        multiset <int> :: iterator it = Set.lower_bound(a[i]);
            
        if (it != Set.end()) {
            ans++;
            Set.erase(it);         
        }
    }
    
    cout << ans;
    
    return 0;
}
