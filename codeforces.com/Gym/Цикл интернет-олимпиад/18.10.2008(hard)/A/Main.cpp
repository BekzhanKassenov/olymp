/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "battle3"

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

int n, m, k, ans;
char a[200][200];

bool ok (int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '.');
}

bool check1 (int x, int y) {
    for (int i = 0; i < k; i++) {
        if (!ok(x - i, y)) {
            return false;
        }
    }
    return true;
}

bool check2 (int x, int y) {
    for (int i = 0; i < k; i++) {
        if (!ok(x, y - i)) {
            return false;
        }
    }
    return true;
}


int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    cin >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#') {
                continue;
            }

            if (check1 (i, j)) {
                ans++;
            }
            if (check2 (i, j)) {
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}
