/****************************************
**          Solution by NU #2          **
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
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, 1, -1, 0};
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int a[MAXN][MAXN];
bool used[MAXN][MAXN];

bool ok(int x, int y) {
    return 1 <= x && x <= n &&
           1 <= y && y <= n;
}

bool edge(int x, int y) {
    return x == 1 || x == n ||
           y == 1 || y == n;
}

int bfs(int x, int y, int h) {
    queue <int> X, Y;

    X.push(x);
    Y.push(y);

    memset(used, false, sizeof used);
    int vol = h - a[x][y];
    used[x][y] = true;

    while (!X.empty()) {
        assert(!Y.empty());

        int xx = X.front();
        int yy = Y.front();

        X.pop();
        Y.pop();

        if (edge(xx, yy)) {
            return -1;
        }

        for (int k = 0; k < 4; k++) {
            int tx = xx + dx[k];
            int ty = yy + dy[k];

            if (ok(tx, ty) && !used[tx][ty] && a[tx][ty] < h) {
                X.push(tx);
                Y.push(ty);

                vol += h - a[tx][ty];
                used[tx][ty] = true;
            }
        }
    }

    return vol;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    int sx = -1, sy = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);

            if (a[i][j] == 0) {
                sx = i, sy = j;
            }
        }
    }

    int l = 0, r = 1000000;

    int ansh = 0, ansv = 0;
    while (l <= r) {
        int mid = (l + r) / 2;

        int v = bfs(sx, sy, mid);

        if (v == -1) {
            r = mid - 1;
        } else {
            l = mid + 1;
            ansh = mid;
            ansv = v;
        }
    }

    printf("%d %d\n", ansh, ansv);
    
    return 0;
}
