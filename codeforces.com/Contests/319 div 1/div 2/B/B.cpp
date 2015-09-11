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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int a[MAXN * MAXN];
bool dp[MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    if (n > m) {
        puts("YES");
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        dp[i][a[i] % m] = true;

        for (int j = 0; j < m; j++) {
            dp[i][j] |= dp[i - 1][(j - a[i] % m + m) % m];
            dp[i][j] |= dp[i - 1][j];
        }
    }

    if (dp[n][0]) {
        puts("YES");
    } else {
        puts("NO");
    }

    return 0;
}
