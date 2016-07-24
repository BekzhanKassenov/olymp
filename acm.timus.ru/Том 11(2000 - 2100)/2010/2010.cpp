#include <iostream>
#include <cstdio>

using namespace std;

int n;

bool ok(int x, int y) {
    return 1 <= x && x <= n
        && 1 <= y && y <= n;
}

int getKing(int x, int y) {
    int ans = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if ((dx != 0 || dy != 0) && ok(x + dx, y + dy)) {
                ans++;
            }
        }
    }

    return ans;
}

int getKnight(int x, int y) {
    static const int dx[] = {-2, -1, 1, 2, -2, -1,  1,  2};
    static const int dy[] = { 1,  2, 2, 1, -1, -2, -2, -1};

    int ans = 0;
    for (int i = 0; i < 8; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];

        if (ok(tx, ty)) {
            ans++;
        }
    }

    return ans;
}

int getBishop(int x, int y) {
    int d1 = n - abs(x - y);
    int d2 = x + y - 1;
    if (d2 > n) {
        d2 = 2 * n - d2;
    }

    return d1 + d2 - 2;
}

int getRook(int x, int y) {
    x = n - 1;
    y = n - 1;
    return x + y;
}

int getQueen(int x, int y) {
    return getBishop(x, y) + getRook(x, y);
}   

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    int x, y;
    scanf("%d%d", &x, &y);

    printf("King: %d\n", getKing(x, y));
    printf("Knight: %d\n", getKnight(x, y));
    printf("Bishop: %d\n", getBishop(x, y));
    printf("Rook: %d\n", getRook(x, y));
    printf("Queen: %d\n", getQueen(x, y));

    return 0;
}
