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

int a, b;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &a, &b);
    
    int k1 = ((a + .0) / (b + .0) - 1) / 2.0;
    int k2 = ((a + .0) / (b + .0) + 1) / 2.0;

    double x = 1e100;

    double temp = (a - b + .0) / (2.0 * k1);
    if (k1 > 0 && temp > 0) {
        x = min(x, temp);
    }

    temp = (a + b + .0) / (2.0 * k2);
    if (k2 > 0 && temp > 0) {
        x = min(x, temp);
    }

    if (x == 1e100) {
        puts("-1");
        return 0;
    }

    printf("%.14lf\n", x);

    return 0;
}
