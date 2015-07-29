#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 210;
const int INF = (int)2e9;
const int di[] = {1, 0, 0, -1};
const int dj[] = {0, 1, -1, 0};

int n, a[MAXN][MAXN];
int dist[MAXN][MAXN];
pair <int, int> par[MAXN][MAXN];

inline bool ok(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    queue <int> X, Y;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d",  &a[i][j]);

            if (a[i][j]) {
                X.push(i);
                Y.push(j);
                dist[i][j] = 0;
                par[i][j] = make_pair(i, j);
            } else {
                dist[i][j] = INF;
                par[i][j] = make_pair(-1, -1);
            }
        }
    }

    while (!X.empty()) {
        int i = X.front();
        int j = Y.front();

        X.pop();
        Y.pop();

        for (int k = 0; k < 4; k++) {
            int ti = i + di[k];
            int tj = j + dj[k];

            if (!ok(ti, tj))
                continue;

            if (dist[ti][tj] == INF) {
                dist[ti][tj] = dist[i][j] + 1;
                par[ti][tj] = par[i][j];
                X.push(ti);
                Y.push(tj); 
            } else if (dist[ti][tj] == dist[i][j] + 1 && par[ti][tj] != par[i][j]) {
                par[ti][tj] = make_pair(ti, tj);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[par[i][j].first][par[i][j].second]);
        }
        puts("");
    }
        
    return 0;
}

