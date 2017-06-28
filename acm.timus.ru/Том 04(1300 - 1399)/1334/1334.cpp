#include <iostream>

using namespace std;

const int dx[] = {-1, -1, 1, 1};
const int dy[] = {1, -1, 1, -1};

int a[8][8];

bool ok(int x, int y) {
    return 0 <= x && x < 8
        && 0 <= y && y < 8;
}


bool can_kill(int x, int y) {
    if (a[x][y] == 0) {
        return false;
    }

    int other = 3 - a[x][y];
    for (int j = 0; j < 4; j++) {
        int tx = x + dx[j];
        int ty = y + dy[j];

        int ttx = x + 2 * dx[j];
        int tty = y + 2 * dy[j];

        if (ok(tx, ty) && ok(ttx, tty)
            && a[tx][ty] == other && a[ttx][tty] == 0) {
            
            return true;
        }
    }

    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    for (int i = 0; i < 32; i++) {
        string s;
        cin >> s;

        int x = s[0] - 'a';
        int y = s[1] - '1';

        a[x][y] = (i & 1) + 1;

        if (can_kill(x, y)) {
            cout << i + 1 << endl;
            return 0;
        }

        for (int j = 0; j < 4; j++) {
            int tx = x + dx[j];
            int ty = y + dy[j];
            if (ok(tx, ty) && can_kill(tx, ty)) {
                cout << i + 1 << endl;
                return 0;
            }
        }
        
    }

    cout << "Draw" << endl;

    return 0;
}