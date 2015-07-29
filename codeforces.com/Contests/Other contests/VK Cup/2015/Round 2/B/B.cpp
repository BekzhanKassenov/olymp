/****************************************
**      Solution by NU: Black Kex      **
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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int a[MAXN], par[MAXN];
int dp[MAXN][2][2];
int dp1[MAXN][2];
vector <int> child[MAXN];

void dfs(int v) {
    if (child[v].empty()) {
        dp[v][0][0] = 0;
        dp[v][0][1] = 0;
        dp[v][1][0] = 0;
        dp[v][1][1] = a[v];
        return;
    }

    int num = child[v].size();
    
    for (int i = 0; i < num; i++) {
        dfs(child[v][i]);
    }

    dp1[0][0] = max(dp[child[v][0]][0][0], dp[child[v][0]][1][0]);
    dp1[0][1] = max(dp[child[v][0]][0][1], dp[child[v][0]][1][1]);

    for (int i = 1; i < num; i++) {
        dp1[i][0] = max(dp1[i - 1][0] + max(dp[child[v][i]][1][0], dp[child[v][i]][0][0]),
                        dp1[i - 1][1] + max(dp[child[v][i]][1][1], dp[child[v][i]][0][1]));

        dp1[i][1] = max(dp1[i - 1][1] + max(dp[child[v][i]][1][0], dp[child[v][i]][0][0]),
                        dp1[i - 1][0] + max(dp[child[v][i]][1][1], dp[child[v][i]][0][1]));
    }

    dp[v][0][0] = dp1[num - 1][0];
    dp[v][1][0] = dp1[num - 1][1] + a[v];
    dp[v][0][1] = dp1[num - 1][1];
    dp[v][1][1] = dp1[num - 1][0] + a[v];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &par[i], &a[i]);

        if (par[i] != -1) {
            child[par[i]].push_back(i);
        }
    }

    dfs(1);

    cout << "i  00 01 10 11" << endl;

    for (int i = 1; i <= n; i++) {
        printf("%2d %2d %2d %2d %2d\n", i, dp[i][0][0], dp[i][0][1], dp[i][1][0], dp[i][1][1]);
    }

    printf("%d\n", max(dp[1][0][0], dp[1][1][0]));

    return 0;
}
