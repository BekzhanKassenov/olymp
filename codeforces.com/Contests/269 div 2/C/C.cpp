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

long long n;

long long f(long long k) {
    return (sqr(k) + 3 * k) / 2;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%I64d", &n);

    long long l = 0, r = 1e7;

    while (l < r) {
        long long mid = (l + r + 1) / 2;

        if (f(mid) <= n)
            l = mid;
        else
            r = mid - 1;
    }

    long long cnt = n - f(l);

    if (cnt % 3 == 0) {
        printf("%I64d\n", l);
        return 0;
    }
    
    l--;
    cnt += 2;

    if (cnt % 3 == 0) {
        printf("%I64d\n", max(0ll, l));
        return 0;
    }

    l--;
    cnt += 8;

    printf("%I64d\n", max(l, 0ll));

    return 0;
}
