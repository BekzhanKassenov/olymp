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

int a, b, c;
int aa, bb, cc;

int gcd(int a, int b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }

    return a + b;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &a, &b, &c);
    scanf("%d%d%d", &aa, &bb, &cc);

    int g = gcd(gcd(aa, bb), cc);

    aa /= g;
    bb /= g;
    cc /= g;

    double cnt = min(min(a / (aa + .0), b / (bb + .0)), c / (cc + .0));
    double ans = aa * cnt + bb * cnt + cc * cnt;

    printf("%.10lf\n", ans);
    
    return 0;
}
