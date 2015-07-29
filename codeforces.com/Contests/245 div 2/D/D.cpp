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
const int maxn = 1010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, m, a[maxn][maxn], ans;
int dtl[maxn][maxn], dbl[maxn][maxn], dtr[maxn][maxn], dbr[maxn][maxn];

void build() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dtl[i][j] = max(dtl[i - 1][j], dtl[i][j - 1]) + a[i][j];
        }
    }

    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= m; j++) {
            dbl[i][j] = max(dbl[i + 1][j], dbl[i][j - 1]) + a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = m; j > 0; j--) {
            dtr[i][j] = max(dtr[i - 1][j], dtr[i][j + 1]) + a[i][j];
        
        }
    }

    for (int i = n; i > 0; i--) {
        for (int j = m; j > 0; j--) {
            dbr[i][j] = max(dbr[i + 1][j], dbr[i][j + 1]) + a[i][j];
        }
    }
}

int best(int i, int j) {
    if (i == 1 || i == n || j == 1 || j == m)
        return 0;

    res = max(res, dtl[i - 1][j] + dbl[i][j - 1] + dbr[i + 1][j] + dtr[i][j + 1]);
    res = max(res, dbl[i + 1][j] + dtl[i][j - 1] + dtr[i - 1][j] + dbr[i][j + 1]);

    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    build();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, best(i, j));
        }
    }

    printf("%d", ans);

    return 0;
}
