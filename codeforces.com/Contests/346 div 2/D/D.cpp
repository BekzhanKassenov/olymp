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

enum DIRECTION {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3
};

int n;
int x[MAXN], y[MAXN];
DIRECTION bad[] = {WEST, NORTH, EAST, SOUTH};

DIRECTION get_dir(int px, int py, int nx, int ny) {
    if (px == nx) {
        if (py < ny) {
            return NORTH;
        }
        
        return SOUTH;
    }

    if (px < nx) {
        return EAST;
    }

    return WEST;
}

bool isBad(int pos) {
    DIRECTION dir1 = get_dir(x[pos - 1], y[pos - 1], x[pos], y[pos]);
    DIRECTION dir2 = get_dir(x[pos], y[pos], x[pos + 1], y[pos + 1]);

    return bad[dir1] == dir2;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans += isBad(i);
    }

    printf("%d\n", ans);

    return 0;
}
