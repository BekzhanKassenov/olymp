/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "twoarcs"

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

int f[400], x, y, x1, y1;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    cin >> x >> y >> x1 >> y1;

    f[x]++;
    while (x != y) {
        x++;
        if (x == 360) {
            x = 0;
        }
        f[x]++;
    }

    if (f[x1] == 1) {
        cout << "YES";
        return 0;
    }

    while (x1 != y1) {
        x1++;
        if (x1 == 360) {
            x1 = 0;
        }

        if (f[x1] == 1) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    return 0;
}
