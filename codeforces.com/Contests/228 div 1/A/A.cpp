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

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    int n;
    cin >> n;
    
    VI a(n);
    vector <bool> used(n);
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
        
    sort(all(a));
    reverse(all(a));
    
    int ans = 0;
    
    while (true) {
        int size = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            if (!used[i]) {
                if (a[i] >= size) {
                    size++;
                    used[i] = true;
                }
            }
        }
        
        ans++;
        
        bool flag = false;
        
        for (int i = 0; i < n; i++)
            if (!used[i])
                flag = true;
                
        if (!flag)
            break;
    }
    
    cout << ans;
    
    return 0;
}