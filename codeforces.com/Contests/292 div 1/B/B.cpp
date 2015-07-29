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
const int INF = 2000 * 1000 * 1000;
const int MAXN = 2010;
const int dx[] = {0, 1, 0, -1}; 
const int dy[] = {1, 0, -1, 0};
const char symb[] = {'>', 'v', '<', '^'};

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
char s[MAXN][MAXN];

bool ok(int x, int y) {
    return 0 <= x && x < n &&
           0 <= y && y < m &&
           s[x][y] == '.';
}

bool one_way(int x, int y) {
    int cnt = 0;

    for (int k = 0; k < 4; k++) {
        int tx = x + dx[k];
        int ty = y + dy[k];

        if (ok(tx, ty)) {
            cnt++;
        }
    }

    return cnt == 1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; i++) {
        gets(s[i]);
    }

    queue <int> X, Y;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (ok(x, y) && one_way(x, y)) {
                X.push(x);
                Y.push(y);
            }
        }
    }

    while (!X.empty()) {
        assert(!Y.empty());

        int x = X.front();
        int y = Y.front();

        X.pop();
        Y.pop();

        if (s[x][y] != '.') {
            continue;
        }

        for (int k = 0; k < 4; k++) {
            int tx = x + dx[k];
            int ty = y + dy[k];

            if (!ok(tx, ty)) {
                continue;
            }
            
            s[tx][ty] = symb[k];
            s[x][y] = symb[(k + 2) % 4];
            for (int kk = 0; kk < 4; kk++) {
                int ttx = tx + dx[kk];
                int tty = ty + dy[kk];

                if (ok(ttx, tty) && one_way(ttx, tty)) {
                    X.push(ttx);
                    Y.push(tty);
                }
            }
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (s[x][y] == '.') {
                puts("Not unique");
                return 0;
            }
        }
    }

    for (int x = 0; x < n; x++) {
        puts(s[x]);
    }
    
    return 0;
}
