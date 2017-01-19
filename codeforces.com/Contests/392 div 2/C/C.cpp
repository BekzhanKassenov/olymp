/****************************************
**     Solution by Bekzhan Kassenov    **
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
const long long INF = 2e18;
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int x, y;
long long k;

long long a[MAXN][MAXN];

void model(long long k) {
    for (int i = 1; i <= n && k > 0; i++) {
        for (int j = 1; j <= m && k > 0; j++) {
            a[i][j]++;
            k--;
        }
    }

    for (int i = n - 1; i > 1 && k > 0; i--) {
        for (int j = 1; j <= m && k > 0; j++) {
            a[i][j]++;
            k--;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n >> m >> k >> x >> y;

    model(k);

    if (k > 0) {
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sum += a[i][j];
            }
        }

        long long cnt = k / sum;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                a[i][j] *= cnt;
            }
        }

        k -= cnt * sum;
        model(k);
    }

    long long mx = -INF, mn = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            mx = max(mx, a[i][j]);
            mn = min(mn, a[i][j]);
        }
    }

    cout << mx << ' ' << mn << ' ' << a[x][y] << endl;

    return 0;
}
