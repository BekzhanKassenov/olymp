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
int a[MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int ans = 0;

    #define process if (a[i][j] == 1) seen = true; \
            if (a[i][j] == 0 && seen) ans++;
    for (int i = 0; i < n; i++) {
        bool seen = false;
        for (int j = 0; j < m; j++) {
            process
        }
        seen = false;
        for (int j = m - 1; j >= 0; j--) {
            process
        }
    }

    for (int j = 0; j < m; j++) {
        bool seen = false;
        for (int i = 0; i < n; i++) {
            process
        }
        seen = false;
        for (int i = n - 1; i >= 0; i--) {
            process
        }
    }

    printf("%d\n", ans);

    return 0;
}
