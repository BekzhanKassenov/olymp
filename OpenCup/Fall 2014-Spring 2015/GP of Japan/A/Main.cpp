/****************************************
**          Solution by NU #2          **
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

const double EPS = 1e-2;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

double a;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%lf", &a);

    double val1 = a * sqrt(2.0);
    double val2 = 0;
    
    if (a >= 1.0 && a <= sqrt(2.0))
        val2 = 2.0;
    else if (a >= 2.0 && a <= sqrt(2.0) + 1)
        val2 = 3.0;

    printf("%.13lf\n", max(val1, val2));

    return 0;
}
