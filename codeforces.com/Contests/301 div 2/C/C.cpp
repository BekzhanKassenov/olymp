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
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, 1, -1, 0};
const int MAXN = 510;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

bool used[MAXN][MAXN];
char s[MAXN][MAXN];
int n, m;
int xs, ys;
int xf, yf;

bool ok(int x, int y) {
    return 1 <= x && x <= n &&
           1 <= y && y <= m;
}

bool dfs(int x, int y) {
    used[x][y] = true;

    if (x == xf && y == yf) {
        return true;
    }

    for (int k = 0; k < 4; k++) {
        int xx = x + dx[k];
        int yy = y + dy[k];

        if (ok(xx, yy) && !used[xx][yy] &&
            s[xx][yy] == '.' && dfs(xx, yy)) {
            
            return true;
        }
    }

    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d %d\n", &n, &m);

    for (int i = 1; i <= n; i++) {
        gets(s[i] + 1);
    }

    scanf("%d%d", &xs, &ys);
    scanf("%d%d", &xf, &yf);

    if (s[xf][yf] == 'X') {
        s[xf][yf] = '.';
        if (dfs(xs, ys)) {
            puts("YES");
        } else {
            puts("NO");
        }

        return 0;
    }

    for (int k = 0; k < 4; k++) {
        int xx = xf + dx[k];
        int yy = yf + dy[k];

        if (ok(xx, yy) && s[xx][yy] == '.') {
            s[xx][yy] = 'X';

            if (dfs(xs, ys)) {
                puts("YES");
                return 0;
            }

            memset(used, false, sizeof(used));
            s[xx][yy] = '.';
        }
    }

    puts("NO");

    return 0;
}
