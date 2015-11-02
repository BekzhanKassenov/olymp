#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

const int MAXN = 810;

bool ok(int n) {
    return 0 <= n && n < MAXN;
}

struct Board {
    int grid[MAXN][MAXN];
    int black;

    void rotate() {
        for (int i = 0; i < MAXN; i++) {
            for (int j = i + 1; j < MAXN; j++) {
                swap(grid[i][j], grid[j][i]);
            }
        }

        for (int i = 0; i < MAXN; i++) {
            reverse(grid[i], grid[i] + MAXN);
        }
    }

    void reflect() {
        for (int i = 0; i < MAXN; i++) {
            reverse(grid[i], grid[i] + MAXN);
        }
    }

    void read() {
        static char buf[MAXN];
        int n, m;

        memset(grid, 0, sizeof grid);
        scanf("%d%d\n", &n, &m);

        black = 0;
        for (int i = 0; i < n; i++) {
            gets(buf);

            for (int j = 0; j < m; j++) {
                if (buf[j] == '#') {
                    grid[i][j] = 1;
                    black++;
                }
            }
        }
    }

    void get_first_black(int& i, int& j) const {
        for (i = 0; i < MAXN; i++) {
            for (j = 0; j < MAXN; j++) {
                if (grid[i][j] == 1) {
                    return;
                }
            }
        }

        i = -1, j = -1;
    }

    bool equal(const Board& other) {
        int di, dj, dio, djo;

        get_first_black(di, dj);
        other.get_first_black(dio, djo);

        int b = black;

        for (int i = -MAXN; i < MAXN; i++) {
            for (int j = -MAXN; j < MAXN; j++) {
                if (!ok(i + di) || !ok(j + dj)) {
                    continue;
                }

                if (!ok(i + dio) || !ok(j + djo)) {
                    continue;
                }

                if (grid[i + di][j + dj] != other.grid[i + dio][j + djo]) {
                    return false;
                }

                if (grid[i + di][j + dj] == 1) {
                    b--;
                }
            }
        }

        return b == 0;
    }

    void print() {
        for (int i = 0; i < MAXN; i++) {
            for (int j = 0; j < MAXN; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
};

Board a, b;

void check() {
    if (a.equal(b)) {
        puts("Yes");
        exit(0);
    }
}

void solve() {
    check();
    a.reflect();
    check();
    a.reflect();
    check();

    for (int i = 0; i < 3; i++) {
        a.rotate();
        check();
        a.reflect();
        check();
        a.reflect();
    }

    //a.rotate();
    a.rotate();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    a.read();
    b.read();

    if (a.black != b.black) {
        puts("No");
        return 0;
    }

    if (a.black == 0 && b.black == 0) {
        puts("Yes");
        return 0;
    }

    solve();
    b.reflect();
   
    solve();
    b.reflect();
    
    for (int i = 0; i < 4; i++) {
        b.rotate();
        solve();
        b.reflect();
        solve();
        b.reflect();
    }

    puts("No");
    
    return 0;
}
