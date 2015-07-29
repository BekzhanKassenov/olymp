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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, w;
int a[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &w);

    for (int i = 1; i <= 2 * n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a + 1, a + 2 * n + 1);

    double x = min(min(w / (3 * n + .0), a[1] + .0), a[n + 1] / 2.0);

    printf("%.10lf\n", 3 * n * x);
    
    return 0;
}
