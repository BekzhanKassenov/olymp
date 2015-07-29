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

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    string s;
    
    cin >> s;
    
    char curc = 0;
    int curcnt = 0;
    
    int ans = 0;
    
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == curc) {
            curcnt++;
        } else {
            if (curc != 0)
                ans += !(curcnt & 1);
            
            curcnt = 1;
            curc = s[i];
        }
    }
    
    if (curc != 0)
        ans += !(curcnt & 1);
    cout << ans; 
    
    return 0;
}
