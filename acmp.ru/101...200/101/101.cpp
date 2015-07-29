#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

int n, k;
int grid[11][11];

int dx[] = {1,  1, -1, -1, 2,  2, -2, -2};
int dy[] = {2, -2,  2, -2, 1, -1,  1, -1};

int ddx[] = {1,  1, -1, -1};
int ddy[] = {1, -1,  1, -1};

bool ok(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void change(int x, int y, int cnt) {
    grid[x][y] += cnt;

    for (int i = 0; i < 8; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];

        if (ok(tx, ty))
            grid[tx][ty] += cnt;
    }

    for (int i = 0; i < n; i++) {
        if (i != x)
            grid[i][y] += cnt;

        if (i != y)
            grid[x][i] += cnt;
    }


    for (int i = 0; i < 4; i++) {
        int tx = x + ddx[i];
        int ty = y + ddy[i];

        while (ok(tx, ty)) {
            grid[tx][ty] += cnt;
            
            tx += ddx[i];
            ty += ddy[i];
        }
    }
}

int last = 0;

ll solve(int k) {
    int cpy = last;

    if (k == 1) {
        int ans = 0;

        for (int i = cpy; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans += !grid[i][j];
            }
        }

        return ans;
    }

    ll ans = 0;

    for (int i = cpy; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!grid[i][j]) {
                change(i, j, 1);
                last = i + 1;
                ans += solve(k - 1);
                change(i, j, -1);
            } 
        }
    }

    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);

    printf("%I64d", solve(k));

    return 0;
}
