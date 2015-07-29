#include <iostream>
#include <cstdio>

using namespace std;

const int INF = 2000 * 1000 * 1000;
const int MAXN = 310;

int g[MAXN][MAXN];
int n, m, x, y;
int ans = 0;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            g[i][j] = INF;

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);

        g[x][y] = min(g[x][y], 0);
        g[y][x] = min(g[y][x], 1);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j && g[i][k] != INF && g[k][j] != INF)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[i][j] != INF)
                ans = max(ans, g[i][j]);
        }
    }

    printf("%d\n", ans);

    return 0;
}
