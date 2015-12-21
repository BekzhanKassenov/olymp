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

long long n, m;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%I64d%I64d", &n, &m);

    if (n > m) {
        swap(n, m);
    }

    long long ans = n * (n + 1);
    ans += (m - n) * n;

    printf("%I64d\n", ans);

    return 0;
}
