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

ll n, a, b;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%I64d%I64d%I64d", &n, &a, &b);
    n *= 6ll;

    if (a * b < n) {
        ll na = a, nb = b;

        for (ll i = a; i * i <= n; i++) {
            ll bb = (n + i - 1) / i;

            if (bb * i < na * 
        }
    }
    
    printf("%I64d\n%I64d %I64d\n", a * b, a, b);

    return 0;
}
