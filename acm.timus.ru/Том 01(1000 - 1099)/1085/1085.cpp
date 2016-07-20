#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int INF = 1e9;
const int MAXN = 110;

int n, m;
int g[MAXN][MAXN];
int money[MAXN], stop[MAXN], has[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = INF;
        }
    }

    for (int i = 1; i <= n; i++) {
        g[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int l;
        scanf("%d", &l);

        vector <int> stops(l);
        for (int j = 0; j < l; j++) {
            scanf("%d", &stops[j]);
        }

        for (int u: stops) {
            for (int v: stops) {
                if (u != v) {
                    g[u][v] = 1;
                }
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (g[i][k] != INF && g[k][j] != INF) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
    }

    int k;
    scanf("%d", &k);

    for (int i = 1; i <= k; i++) {
        scanf("%d%d%d", &money[i], &stop[i], &has[i]);
        money[i] /= 4;
    }

    /*
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", g[i][j]);
        }
        puts("");
    }
    */

    int ans = INF;
    int num = -1;
    for (int i = 1; i <= n; i++) {
        bool ok = true;
        int sum = 0;
        for (int j = 1; j <= k; j++) {
            if (g[stop[j]][i] == INF || (!has[j] && g[stop[j]][i] > money[j])) {
                ok = false;
            } else {
                if (!has[j]) {
                    sum += g[stop[j]][i];
                }
            }
        }

        if (ok && sum < ans) {
            ans = sum;
            num = i;
        }
    }

    if (ans == INF) {
        puts("0");
    } else {
        printf("%d %d\n", num, ans * 4);
    }

    return 0;
}
