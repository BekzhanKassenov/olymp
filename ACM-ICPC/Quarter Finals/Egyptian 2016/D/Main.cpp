/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "popcorn"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int main() {
    freopen(File".in", "r", stdin);
    
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        int ans = 1;
        int ptr = 2;
        for (int i = n - m + 1; i <= n; i++) {
            ans *= i;
            while (ans % ptr == 0 && ptr <= m) {
                ans /= ptr;
                ptr++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
