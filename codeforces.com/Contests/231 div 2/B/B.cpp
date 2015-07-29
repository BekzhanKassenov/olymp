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
    freopen("out", "w", stdout);
#endif

    int p, n;
    
    cin >> p >> n;
    
    for (int start = 1; start <= 9; start++) {
        int rem = 0, cur = start;
        
        for (int i = 0; i < p; i++) {
            int nxt = cur * n + rem;
            rem = nxt / 10;
            cur = nxt % 10;
        }
        
        if (rem == 0 && cur == start) {
            string res;
            res += (start + '0');
            
            for (int i = 0; i < p - 1; i++) {
                int nxt = cur * n + rem;
                rem = nxt / 10;
                cur = nxt % 10;
                res += (cur + '0');
            }
            
            reverse(all(res));
            if (res[0] == '0')
                continue;
            cout << res << endl;
            return 0;
        }
    }
    
    cout << "Impossible" << endl;
    
    return 0;
}
