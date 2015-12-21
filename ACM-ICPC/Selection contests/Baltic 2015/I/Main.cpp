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

double r, R, h;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    cin >> r >> R >> h;

    double H = (h * R) / (R - r);

    double ans1 = h / 2;
    
    double S = H * R;
    double p = R + sqrt(sqr(H) + sqr(R));

    double ans2 = S / p;

    printf("%.10lf\n", min(ans1, ans2));
    
    return 0;
}
