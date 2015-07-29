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
#define File "power"

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

int f(int n) {
    int res = 0;
    
    while (n) {
        res += n % 10;
        n /= 10;
    }
    
    return res;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    int power = 1;
    
    for (int n = 1; n <= 8; n++) {
        ll ans = 0;
    
        power *= 10;
        for (int i = 2; i <= power; i++)
            ans += f(i);
        
        cout << n << ' ' << ans << endl;
    }
    return 0;
}
