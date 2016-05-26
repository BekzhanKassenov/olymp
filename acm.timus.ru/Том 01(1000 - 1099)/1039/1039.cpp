#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 6010;

int n;
vector <int> g[MAXN];
int conv[MAXN];
int dp[2][MAXN];
bool root[MAXN];

void dfs(int v) {
    int s0 = 0, s1 = 0;
    for (int to: g[v]) {
        dfs(to);
        s0 += max(dp[0][to], dp[1][to]);
        s1 += dp[0][to];
    }

    dp[0][v] = s0;
    dp[1][v] = s1 + conv[v];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &conv[i]);
        root[i] = true;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[v].push_back(u);
        root[u] = false;
    }

    int start = 0;
    for (int i = 1; i <= n; i++) {
        if (root[i]) {
            start = i;
            break;
        }
    }

    dfs(start);

    printf("%d\n", max(dp[0][start], dp[1][start]));

    return 0;
}
