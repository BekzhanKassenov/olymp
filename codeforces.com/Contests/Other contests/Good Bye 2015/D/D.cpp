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
const int MAXN = 5010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
char s[MAXN];
int dp[MAXN][MAXN];
int z[MAXN][MAXN + MAXN];
char table[MAXN][MAXN + MAXN];

void build(int row) {
    for (int i = 1, l = 0, r = 0; table[row][i]; i++) {
        if (i <= r) {
            z[row][i] = min(z[row][i - l], r - i + 1);
        }

        while (table[row][z[row][i]] == table[row][i + z[row][i]]) {
            z[row][i]++;
        }
    
        if (i + z[row][i] - 1 > r) {
            l = i, r = i + z[row][i] - 1;
        }
    }
}

// less
bool compare(int a, int b, int len) {
    int lcp = z[a][n - a + 1 + b];

    if (lcp >= len) {
        return false;
    }

    return s[a + lcp] < s[b + lcp];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);
    gets(s);

    for (int i = 0; i < n; i++) {
        strcpy(table[i], s + i);
        strcat(table[i], "#");
        strcat(table[i], s);

        build(i);
    }

    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i; j++) {
            if (s[j] == '0') {
                continue;
            }

            int len = i - j + 1;

            dp[i][j] = dp[j - 1][j - 1];

            if (j - len >= 0) {
                dp[i][j] -= dp[j - 1][j - len];
                dp[i][j] %= MOD;
                dp[i][j] += MOD;
                dp[i][j] %= MOD;
            }

            if (j - len >= 0 && s[j - len] != '0' && compare(j - len, j, len)) {
                dp[i][j] += dp[j - 1][j - len];

                if (j - len - 1 >= 0) {
                    dp[i][j] -= dp[j - 1][j - len - 1];
                }

                dp[i][j] %= MOD;
                dp[i][j] += MOD;
                dp[i][j] %= MOD;
            }
        }   

        for (int j = 1; j <= i; j++) {
            dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }

    printf("%d\n", dp[n - 1][n - 1]);

    return 0;
}
