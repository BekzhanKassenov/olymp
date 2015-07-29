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

bool check(int mask, int n) {
    for (int i = 0; i <= n; i++) {
        if (!(mask & (1 << i)))
            continue;
            
        for (int j = 0; j <= n; j++) {
            if (!(mask & (1 << j)))
                continue;
                
            if (!(mask & (1 << (i ^ j))))
                return false;
        }
    }
    
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    for (int n = 0; n <= 20; n++) {
        int ans = 0;
        
        for (int mask = 1; mask < (1 << (n + 1)); mask++) {
            ans += check(mask, n);
        }
        
        cout << ans << ", ";
    }
    
    return 0;
}
