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

int a[50][50];
int sum[50][50];

int get_sum(int x, int y, int _x, int _y) {
    return (sum[x][y] - sum[_x - 1][y] - sum[x][_y - 1] + sum[_x - 1][_y - 1]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = i; k <= n; k++) {
                for (int l = j; l <= m; l++) {
                    if ((l - j + 1) % 2 == 0) {
                        int mid = (j + (l - j + 1) / 2 - 1);
                        int sum = get_sum(k, mid, i, j) - get_sum(k, l, i, mid + 1);

                        if (sum == 0) {
                            ans++;
                        }
                    }
                }
            }
        }
    }

    cout << ans;
    return 0;
}
