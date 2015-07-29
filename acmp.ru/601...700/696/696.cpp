#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int INF = 2000 * 1000 * 1000;

int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
int n, m, cost[4];
char t[55][55];
bool used[55][55];

bool ok(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m 
           && t[x][y] != 'X' && !used[x][y];
}

int num(char c) {
    if (c == 'R')
        return 0;

    if (c == 'G')
        return 1;

    if (c == 'B')
        return 2;

    return 3;
}

bool dfs(int x, int y, int mask) {
    used[x][y] = true;

    if (t[x][y] == 'E')
        return true;

    if (t[x][y] != '.' && t[x][y] != 'S') {
        if (!(mask & (1 << num(t[x][y]))))
            return false;
    }

    bool res = false;

    for (int i = 0; i < 4 && !res; i++) {
        int tx = x + dx[i];         
        int ty = y + dy[i];

        if (ok(tx, ty))
            res |= dfs(tx, ty, mask);
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d", &n, &m);

    scanf("%d %d %d %d\n", cost, cost + 1, cost + 2, cost + 3);

    for (int i = 0; i < n; i++)
        gets(t[i]);

    int sx = 0, sy = 0, ex = 0, ey = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (t[i][j] == 'S') {
                sx = i, sy = j;
            } else if (t[i][j] == 'E') {
                ex = i, ey = j;
            }
    }

    int ans = INF;

    for (int mask = 0; mask < (1 << 4); mask++) {
        memset(used, false, sizeof used);

        dfs(sx, sy, mask);

        if (used[ex][ey]) {
            int sum = 0;
            for (int i = 0; i < 4; i++)
                if (mask & (1 << i))
                    sum += cost[i];

            ans = min(ans, sum); 
        }
    }

    if (ans == INF)
        puts("Sleep");
    else
        printf("%d\n", ans);

    return 0;
}
