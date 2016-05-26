#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 510;
const long long INF = (long long)3e18;

enum DIR {
    BAD,
    BOT,
    LEFT,
    RIGHT
};

int n, m;
long long a[MAXN][MAXN];
long long dp_b[MAXN][MAXN], dp_l[MAXN][MAXN], dp_r[MAXN][MAXN];
long long dp[MAXN][MAXN];
DIR par[MAXN][MAXN];

bool shift(int& i, int& j) {
    switch (par[i][j]) {
        case BAD:
            return false;

        case BOT:
            i--;
            break;

        case LEFT:
            j--;
            break;

        case RIGHT:
            j++;
    }

    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            dp_b[i][j] = INF;
            dp_l[i][j] = INF;
            dp_r[i][j] = INF;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%lld", &a[i][j]);
        }
    }

    for (int j = 1; j <= m; j++) {
        dp[1][j] = a[1][j];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp_b[i][j] = dp[i - 1][j] + a[i][j];
        }

        for (int j = 1; j <= m; j++) {
            dp_l[i][j] = min(dp_l[i][j - 1], dp_b[i][j - 1]) + a[i][j];
        }

        for (int j = m; j >= 1; j--) {
            dp_r[i][j] = min(dp_r[i][j + 1], dp_b[i][j + 1]) + a[i][j];
        }

        for (int j = 1; j <= m; j++) {
            long long mn = min(min(dp_l[i][j], dp_r[i][j]), dp_b[i][j]);
            dp[i][j] = mn;

            if (mn == dp_l[i][j]) {
                par[i][j] = LEFT;
            } else if (mn == dp_r[i][j]) {
                par[i][j] = RIGHT;
            } else if (mn == dp_b[i][j]) {
                par[i][j] = BOT;
            }
        }
    }

    int mn = 1;
    for (int j = 2; j <= m; j++) {
        if (dp[n][j] < dp[n][mn]) {
            mn = j;
        }
    }

    int x = n, y = mn;
    vector <int> ans;

    do {
        ans.push_back(y);
    } while (shift(x, y));

    reverse(ans.begin(), ans.end());

    for (int temp: ans) {
        printf("%d ", temp);
    }
    puts("");

    return 0;
}
