/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "garland"

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
int a[1000001][3];
int b[1000001][3];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
    }
    b[0][0] = a[0][0];
    b[0][1] = a[0][1];
    b[0][2] = a[0][2];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int mn = INF;
            for (int k = 0; k < 3; k++) {
                if (j == k)
                    continue;
                mn = min(mn, b[i-1][k]);
            }
            b[i][j] = mn + a[i][j];
        }
    }

    cout << min(b[n-1][0], min(b[n-1][2], b[n-1][1]));
    return 0;
}
