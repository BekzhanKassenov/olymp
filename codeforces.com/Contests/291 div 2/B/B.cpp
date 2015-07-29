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

int n, x, y, _x, _y;
set <pair <int, int> > Set;

pair <int, int> get_slope(int x, int y) {
    if (x < 0) {
        x *= -1;
        y *= -1;
    }

    if (x == 0) {
        return make_pair(0, 1);
    }
    
    if (y == 0) {
        return make_pair(1, 0);
    }

    int g = __gcd(abs(x), abs(y));
    x /= g;
    y /= g;
    return make_pair(x, y);
}

bool has;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &_x, &_y);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);

        x -= _x;
        y -= _y;

        if (x != 0 || y != 0) {
            Set.insert(get_slope(x, y));
        }
    }
    
    printf("%u", max(1u, Set.size()));

    return 0;
}
