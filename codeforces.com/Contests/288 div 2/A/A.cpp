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

int n, m, k, xx, yy;
int a[MAXN][MAXN];

bool ok(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

bool check(int x, int y) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (!ok(x + i, y + j))
                return false;

            if (a[x + i][y + j] != 1)
                return false;
        }
    }

    return true;
}

bool checkCell(int x, int y) {
    return check(x, y) || check(x - 1, y) || check(x, y - 1) || check(x - 1, y - 1);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; i++) { 
        scanf("%d%d", &xx, &yy);

        a[xx][yy] = 1;
        if (checkCell(xx, yy)) {
            printf("%d\n", i);
            return 0;
        }
    }

    printf("%d\n", 0);

    return 0;
}
