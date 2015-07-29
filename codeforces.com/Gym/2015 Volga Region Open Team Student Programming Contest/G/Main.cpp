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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k;
int c[MAXN];
char dp[MAXN][MAXN];
int lasti = 0, lastj = 0;
char result[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }

    dp[0][0] = ' ';
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j - c[i] >= 0 && dp[i - 1][j - c[i]] != '\0') {
                dp[i][j] = '+';
                lasti = i;
                lastj = j;
            } else if (j + c[i] <= k && dp[i - 1][j + c[i]] != '\0') {
                dp[i][j] = '-';
                lasti = i;
                lastj = j;
            }
        }
    }

    printf("%d\n", lasti);

    for (int i = lasti; i > 0; i--) {
        result[i] = dp[i][lastj];

        if (dp[i][lastj] == '+') {
            lastj -= c[i];
        } else {
            lastj += c[i];
        }
    }

    puts(result + 1);

    return 0;
}
