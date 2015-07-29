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

ll n, x, y;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%I64d%I64d%I64d", &n, &x, &y);

    if (n > y) {
        puts("-1");
        return 0;
    }

    ll sum = sqr(y - n + 1) + n - 1;

    if (sum >= x) {
        printf("%I64d\n", y - n + 1);

        for (int i = 0; i < n - 1; i++)
            puts("1");
    } else {
        puts("-1");
    }
    
    return 0;
}
