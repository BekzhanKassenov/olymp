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

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int s, x1, x2;
    scanf("%d%d%d", &s, &x1, &x2);

    int t1, t2;
    scanf("%d%d", &t1, &t2);

    int p, d;
    scanf("%d%d", &p, &d);

    if (x1 > x2) {
        x1 = s - x1;
        x2 = s - x2;
        p = s - p;
        d *= -1;
    }

    int tdist = 0;
    if (d == -1) {
        tdist = p + x2;
    } else {
        if (p <= x1) {
            tdist = x2 - p;
        } else {
            tdist = 2 * s + x2 - p;
        }
    }
    
    printf("%d\n", min((x2 - x1) * t2, tdist * t1));

    return 0;
}
