/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

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

int T;
int n;
map <string, int> Map;
string s, t;
long long ans;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    cin >> T;

    while (T--) {
        ans = 1;
        Map.clear();

        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> s >> t;

            Map[t]++;
        }

        for (auto it: Map) {
            ans *= it.second + 1;
        }

        cout << ans - 1 << endl;
    }
    
    return 0;
}
