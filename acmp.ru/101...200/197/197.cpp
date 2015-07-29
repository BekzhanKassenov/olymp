#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

int n, a[110][110];
int x, y, num = 1;
int di = 1, dj = 0, dx = 1, dy = -1;

bool ok(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void fill() {
    while (ok(x, y)) {
        a[x][y] = num++;
        x += dx;
        y += dy;
    }

    x -= dx;
    y -= dy;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    while (num <= n * n) {
        fill();
        
        if (!ok(x + di, y + dj))
            swap(di, dj);

        x += di;
        y += dj;
        
        swap(di, dj);
        
        dx *= -1;
        dy *= -1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);

        puts("");
    }

    return 0;
}