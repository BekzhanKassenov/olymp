#include <iostream>
#include <cstdio>
#include <queue>
#include <cassert>

using namespace std;

int dx[] = {1, 0, -1,  0};
int dy[] = {0, 1,  0, -1};
char dir[] = {'R', 'T', 'L', 'B'};

int table[15][15];
int n, m;
char temp[20];

void read_first() {
    int x, y;

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        table[x][y] = true;
    }
}

void read_second() {
    int sx = n, sy = m;

    queue <int> X, Y;
    X.push(sx);
    Y.push(sy);

    while (!X.empty()) {
        assert(!Y.empty());
        gets(temp);

        int x = X.front();
        int y = Y.front();
        table[x][y] = true;

        X.pop();
        Y.pop();

        for (int i = 0; temp[i]; i++) {
            for (int k = 0; k < 4; k++) {
                if (temp[i] == dir[k]) {
                    int tx = x + dx[k];
                    int ty = y + dy[k];

                    X.push(tx);
                    Y.push(ty);
                }
            }
        }
    }
}

void print_first() {
    int ans = 0;
    for (int x = 0; x <= 10; x++) {
        for (int y = 0; y <= 10; y++) {
            ans += table[x][y];
        }
    }

    printf("%d\n", ans);
    for (int x = 0; x <= 10; x++) {
        for (int y = 0; y <= 10; y++) {
            if (table[x][y])
                printf("%d %d\n", x, y);
        }
    }
}

void print_second() {
    int sx = -1, sy = -1;
    for (int x = 0; x <= 10; x++) {
        for (int y = 0; y <= 10; y++) {
            if (table[x][y]) {
                sx = x;
                sy = y;
                break;
            }
        }

        if (sx != -1)
            break;
    }

    queue <int> X, Y;
    printf("%d %d\n", sx, sy);

    X.push(sx);
    Y.push(sy);
    table[sx][sy] = false;

    while (!X.empty()) {
        assert(!Y.empty());
        int x = X.front();
        int y = Y.front();

        X.pop();
        Y.pop();

        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];

            //printf("%d %d %d %c\n", tx, ty, table[tx][ty], dir[i]);

            if (tx >= 0 && ty >= 0 && table[tx][ty]) {
                table[tx][ty] = false;
                X.push(tx);
                Y.push(ty);
                putchar(dir[i]);
            }
        }

        if (!X.empty())
            putchar(',');
        else
            putchar('.');

        putchar('\n');
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(temp);

    if (sscanf(temp, "%d %d\n", &n, &m) == 2) {
        read_second();
        print_first();
    } else {
        read_first();
        print_second();
    }

    return 0;
}
