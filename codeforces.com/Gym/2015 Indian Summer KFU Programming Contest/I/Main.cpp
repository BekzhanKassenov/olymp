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

int n, m, xx, yy, _x, _y;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    scanf("%d%d%d%d%d%d", &n, &m, &xx, &yy, &_x, &_y);

    if (abs(xx - _x) <= 1 && abs(yy - _y) <= 1) {
       puts("-1");
       return 0;
    }

    if (abs(xx - _x) > 1) {
        printf("X %d", min(xx, _x) + 1);
    } else {
        printf("Y %d", min(yy, _y) + 1);
    }
    
    return 0;
}
