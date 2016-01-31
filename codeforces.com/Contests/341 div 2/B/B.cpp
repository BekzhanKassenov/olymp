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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
bool grid[MAXN][MAXN];

bool ok(int x, int y) {
    return 1 <= x && x <= 1000 &&
           1 <= y && y <= 1000;
}

long long go(int xx, int yy, int dx, int dy) {
    long long result = 0;
    while (ok(xx, yy)) {
        if (grid[xx][yy]) {
            result++;
        }

        xx += dx;
        yy += dy;
    }

    if (result == 0) {
        return 0;
    }

    return result * (result - 1) / 2;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        grid[x][y] = true;
    }

    long long ans = 0;
    for (int i = 1; i <= 1000; i++) {
        ans += go(1, i, 1, 1);
        ans += go(1, i, 1, -1);
    }

    for (int i = 2; i <= 1000; i++) {
        ans += go(i, 1, 1, 1);
        ans += go(i, 1000, 1, -1); 
    }

    cout << ans << endl;

    return 0;
}
                    