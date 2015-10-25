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
const int INF = 500 * 1000 * 1000;
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, 1, -1, 0};
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

bool used[MAXN][MAXN];
int dist1[MAXN][MAXN];
int dist2[MAXN][MAXN];
int dist3[MAXN][MAXN];
int a[MAXN][MAXN];
char buf[MAXN];
int n, m;

bool ok(int x, int y) {
    return 1 <= x && x <= n &&
           1 <= y && y <= m;
}

void bfs(int country, int dist[MAXN][MAXN]) {
    queue <int> X, Y;
    memset(used, false, sizeof (used));

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            dist[x][y] = INF;

            if (a[x][y] == country || a[x][y] == -1) {
                used[x][y] = true;
            }
        }
    }

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            if (a[x][y] == country) {
                for (int k = 0; k < 4; k++) {
                    int tx = x + dx[k];
                    int ty = y + dy[k];

                    if (ok(tx, ty) && !used[tx][ty]) {
                        dist[tx][ty] = 1;
                        X.push(tx);
                        Y.push(ty);
                        used[tx][ty] = true;
                    }
                }
            }
        }
    }

    while (!X.empty()) {
        assert(!Y.empty());

        int xx = X.front();
        X.pop();

        int yy = Y.front();
        Y.pop();

        for (int k = 0; k < 4; k++) {
            int tx = xx + dx[k];
            int ty = yy + dy[k];

            if (ok(tx, ty) && !used[tx][ty]) {
                dist[tx][ty] = dist[xx][yy] + 1;
                X.push(tx);
                Y.push(ty);
                used[tx][ty] = true;
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d\n", &n, &m);

    for (int i = 1; i <= n; i++) {
        gets(buf);

        for (int j = 1; j <= m; j++) {
            if (buf[j - 1] == '#') {
                a[i][j] = -1;
            } else if (buf[j - 1] == '.') {
                a[i][j] = 0;
            } else {
                a[i][j] = buf[j - 1] - '0';
            }
        }
    }

    bfs(1, dist1);
    bfs(2, dist2);
    bfs(3, dist3);

    int ans = INF;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 0) {
                ans = min(ans, dist1[i][j] + dist2[i][j] + dist3[i][j] - 2);
            }
        }
    }

    int min11 = INF, min12 = INF;
    int min21 = INF, min22 = INF;
    int min31 = INF, min32 = INF;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            switch (a[i][j]) {
                case 1:
                    min11 = min(min11, dist2[i][j] - 1);
                    min12 = min(min12, dist3[i][j] - 1);
                    break;

                case 2:
                    min21 = min(min21, dist1[i][j] - 1);
                    min22 = min(min22, dist3[i][j] - 1);
                    break;

                case 3:
                    min31 = min(min31, dist1[i][j] - 1);
                    min32 = min(min32, dist2[i][j] - 1);
                    break;
            }
        }
    }

    ans = min(ans, min11 + min12);
    ans = min(ans, min21 + min22);
    ans = min(ans, min31 + min32);

    if (ans == INF) {
        puts("-1");
    } else {
        printf("%d\n", ans);
    }

    return 0;
}
