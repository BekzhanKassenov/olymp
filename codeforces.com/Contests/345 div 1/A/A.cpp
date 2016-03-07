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

int n;
map <int, int> X, Y;
map <pair <int, int>, int> XY;
long long ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);

        ans += X[x];
        ans += Y[y];
        ans -= XY[make_pair(x, y)];

        X[x]++;
        Y[y]++;
        XY[make_pair(x, y)]++;
    }

    printf("%lld\n", ans);

    return 0;
}
