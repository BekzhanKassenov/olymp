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

int x, y, _x, _y;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d%d", &x, &y, &_x, &_y);

    if (x != _x && y != _y) {
        if (abs(x - _x) == abs(y - _y))
            printf("%d %d %d %d\n", x, _y, _x, y);
        else
            puts("-1");
    } else {
        if (x == _x) {
            int diff = abs(y - _y);

            printf("%d %d %d %d", x + diff, y, _x + diff, _y);
        } else {
            int diff = abs(x - _x);
            printf("%d %d %d %d", x, y + diff, _x, _y + diff);
        }
    }
    
    return 0;
}
