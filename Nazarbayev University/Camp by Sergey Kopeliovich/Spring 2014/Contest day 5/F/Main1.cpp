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
#define File "mouse"

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

int n;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    cin >> n;
    
    if (n == 1) {
        cout << 1 << endl << 1;
    } else if (n == 2) {
        cout << 2 << endl << 1 << ' ' << 1;
    } else {
        cout << 2 * (n - 2) << endl;
         
        for (int i = 2; i < n; i++) {
            cout << i << ' ' << i << ' ';
        }
    }
    
    return 0;
}
