/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "ascii"

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

int n, m;
char c[200][200];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    cin >> n >> m;

    int bord = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];

            if (c[i][j] != '.') {
                bord++;    
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        bool open = false;

        for (int j = 0; j < m; j++) {
            if (c[i][j] == '.') {
                res += open;
            } else {
                open ^= 1;
            }
        }
    }

    cout << res + bord / 2 << endl;

    return 0;
}
