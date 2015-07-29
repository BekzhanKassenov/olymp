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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, ans;
int grid[50][50];

int ddx[] = {1, 0, 0, -1};
int ddy[] = {0, 1, -1, 0};

int dx[] = {2, 2, -2, -2};
int dy[] = {1, -1, 1, -1};

bool ok(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void build(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int tx = x + ddx[i];
        int ty = y + ddy[i];

        if (ok(tx, ty)) {
            grid[tx][ty] = 0;
            grid[x][y]++;
        }
    }

    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];

        if (ok(tx, ty) && grid[tx][ty] == 1) {
            build(tx, ty);
        }
    }
}

void clear() {
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 50; j++)
            grid[i][j] = 1;
}

int solve() {
    int res = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            clear();
            build(i, j);

            int cnt = 0;

            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    cnt += !grid[x][y];
                }
            }

            res = max(res, cnt);
        }
    }

    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d", &n, &m);

    if (n < m)
        swap(n, m);

    ans = solve();

    printf("%d\n", ans);

    return 0;
}
