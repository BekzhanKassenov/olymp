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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n, k;
char s[3][MAXN];
bool used[3][MAXN];

bool ok(int x, int y) {
    return 0 <= x && x < 3 &&
           0 <= y && y < n &&
           s[x][y] == '.';
}

bool move(int x, int y, int delta) {
    bool result = true;
    
    y++;
    result &= ok(x, y);

    x += delta;
    result &= ok(x, y);

    y++;
    result &= ok(x, y);

    y++;
    result &= ok(x, y);

    return result;
}

bool exit(int x, int y, int delta) {
    bool result = false;
    
    y++;

    if (y == n - 1 && s[x][y] == '.') {
        return true;
    }

    if (s[x][y] != '.') {
        return false;
    }

    x += delta;
    if (!ok(x, y)) {
        return false;
    }

    for (int i = 0; i < 2; i++) {
        y++;

        if (y == n - 1 && s[x][y] == '.') {
            return true;
        }

        if (s[x][y] != '.') {
            return false;
        }
    }

    return result;
}

bool bfs(int sx, int sy) {
    queue <int> X, Y;

    X.push(sx);
    Y.push(sy);

    used[sx][sy] = true;

    while (!X.empty()) {
        assert(!Y.empty());

        int x = X.front();
        X.pop();

        int y = Y.front();
        Y.pop();


        for (int delta = -1; delta <= 1; delta++) {
            if (exit(x, y, delta)) {
                return true;
            }

            if (move(x, y, delta) && !used[x + delta][y + 3]) {
                X.push(x + delta);
                Y.push(y + 3);
                used[x + delta][y + 3] = true;
            }
        }
    }
    
    return false;
}

void clear() {
    for (int i = 0; i < 3; i++) {
        memset(used[i], false, sizeof(bool) * (n + 1));;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &T);

    while (T--) {
        scanf("%d %d\n", &n, &k);
        for (int i = 0; i < 3; i++) {
            gets(s[i]);
        }

        clear();

        int sx = -1, sy = -1;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i][j] == 's') {
                    sx = i, sy = j;
                    s[i][j] = '.';
                }
            }
        }
    
        if (bfs(sx, sy)) {
            puts("YES");
        } else {
            puts("NO");
        }
    }

    return 0;
}
