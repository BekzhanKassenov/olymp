/****************************************
**          Solution by NU #2          **
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
const int MAXN = 510;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int a[MAXN], b[MAXN];
int dp[MAXN][MAXN];

bool ok(int i, int j, int k, int l) {
    return (b[i] - b[j]) * (a[k] - a[l]) > 0;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int j = 1; j <= m; j++) {
        scanf("%d", &b[j]);
    }

    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            dp[i][j] = INF;
        }
    }

    if (n == 1) {
        puts("Yes");
        return 0;
    }

    if (m < n) {
        puts("No");
        return 0;
    }

    if (n == 2) {
        for (int i = 1; i <= m; i++) {
            for (int j = i + 1; j <= m; j++) {
                if (ok(j, i, 2, 1)) {
                    puts("Yes");
                    return 0;
                }
            }
        }

        puts("No");
        return 0;
    }

    if (n == 3) {
        for (int i = 1; i <= m; i++) {
            for (int j = i + 1; j <= m; j++) {
                for (int k = j + 1; k <= m; k++) {
                    if (ok(j, i, 2, 1) && ok(k, j, 3, 2) && ok(k, i, 3, 1)) {
                        puts("Yes");
                        return 0;
                    }
                }
            }
        }

        puts("No");
        return 0;
    }

    if (a[1] == 1) {
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == INF) {
                    continue;
                }

                for (int k = i + 1; k <= m; k++) {
                    if (b[k] > b[i]) {
                        dp[k][j + 1] = 1;
                    }
                }
            }
        }

        if (a[n] == n) {
            for (int i = 1; i <= m; i++) {
                if (dp[i][n] == 1) {
                    puts("Yes");
                    return 0;
                }
            }

            puts("No");
        } else {
            for (int i = 1; i <= m; i++) {
                if (dp[i][n - 2] == 1) {
                    for (int p1 = i + 1; p1 <= m; p1++) {
                        for (int p2 = p1 + 1; p2 <= m; p2++) {
                            if (ok(p2, p1, n, n - 1) && ok(p1, i, n - 1, n - 2) && ok(p2, i, n, n - 2)) {
                                puts("Yes");
                                return 0;
                            }
                        }
                    }
                }
            }

            puts("No");
        }
    } else {
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == INF) {
                    continue;
                }

                for (int k = i + 1; k <= m; k++) {
                    if (b[k] < b[i]) {
                        dp[k][j + 1] = 1;
                    }
                }
            }
        }

        if (a[n] == 1) {
            for (int i = 1; i <= m; i++) {
                if (dp[i][n] == 1) {
                    puts("Yes");
                    return 0;
                }
            }

            puts("No");
        } else {
            for (int i = 1; i <= m; i++) {
                if (dp[i][n - 2] == 1) {
                    for (int p1 = i + 1; p1 <= m; p1++) {
                        for (int p2 = p1 + 1; p2 <= m; p2++) {
                            if (ok(p2, p1, n, n - 1) && ok(p1, i, n - 1, n - 2) && ok(p2, i, n, n - 2)) {
                                puts("Yes");
                                return 0;
                            }
                        }
                    }
                }
            }

            puts("No");
        }
    }
    
    return 0;
}
