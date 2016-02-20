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
const int INF = 2000 * 1000 * 1000;
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;

int a[MAXN][MAXN];
int sum[MAXN][MAXN];

int getSum(int xl, int yd, int xr, int yt) {
    xr = min(xr, n);
    yt = min(yt, n);

    return sum[xr][yt] - sum[xr][yd - 1] - sum[xl - 1][yt] + sum[xl - 1][yd - 1];
}

int check(int lx, int ly) {
    int ans = m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans = min(ans, m - getSum(i, j, i + lx - 1, j + ly - 1));
        }
    }

    return ans;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x][y] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }

    int ans = m;
    for (int i = 1; i * i <= m; i++) {
        if (m % i == 0) {
            ans = min(min(ans, check(i, m / i)), check(m / i, i));
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
