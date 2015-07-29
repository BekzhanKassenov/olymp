#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define F first
#define S second

const int maxn = 500;
vector <pair <int, int> > edges;
int mat[maxn][maxn], n, m, cost[maxn], x, y;

int main() {
    #ifdef Local
        freopen("in", "r", stdin);
    #endif

    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 0; i < n; i++)
            scanf("%d", &cost[i]);

        memset(mat, 0, sizeof mat);
        edges.resize(m);
        int ans = 0;
        for (int i = 0; i < m; i++) {
            cin >> edges[i].F >> edges[i].S;
            mat[--edges[i].F][--edges[i].S] = true;
            mat[edges[i].S][edges[i].F] = true;

            ans = max(ans, cost[edges[i].F] + cost[edges[i].S]);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (edges[i].F != j && edges[i].S != j) {
                    if (mat[edges[i].F][j] && mat[edges[i].S][j])
                        ans = max(ans, cost[edges[i].F] + cost[edges[i].S] + cost[j]);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                int a = edges[i].F, b = edges[i].S, c = edges[j].F, d = edges[j].S;

                if (a != b && a != c && a != d && b != c && b != d && c != d) {
                    if (mat[a][b] && mat[a][c] && mat[a][d] && mat[b][c] && mat[b][d] && mat[c][d])
                        ans = max(ans, cost[a] + cost[b] + cost[c] + cost[d]);
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
