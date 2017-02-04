/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "commandos"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 12;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int dp[MAXN][MAXN][MAXN];
int a[MAXN][MAXN][MAXN];

int main() {
    freopen(File".in", "r", stdin);
    
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        for (int f = 0; f <= 10; f++) {
            for (int y = 0; y <= 10; y++) {
                for (int x = 0; x <= 10; x++) {
                    dp[f][y][x] = 0;
                    a[f][y][x] = 0;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            int f, y, x, h;
            cin >> f >> y >> x >> h;
            a[f][y][x] = h;
        }

        dp[10][1][1] = a[10][1][1];
        for (int f = 10; f > 0; f--) {
            for (int x = 1; x <= 10; x++) {
                for (int y = 1; y <= 10; y++) {
                    if (f < 10) {
                        dp[f][x][y] = max(dp[f][x][y], dp[f + 1][x][y] + a[f][x][y]);
                    }

                    if (y > 1) {
                        dp[f][x][y] = max(dp[f][x][y], dp[f][x][y - 1] + a[f][x][y]);
                    }

                    if (x > 1) {
                        dp[f][x][y] = max(dp[f][x][y], dp[f][x - 1][y] + a[f][x][y]);
                    }
                }
            }
        }

        cout << dp[1][10][10] << endl;
    }

    return 0;
}
