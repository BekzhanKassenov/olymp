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

template <typename T>
inline T cube(T n) {
    return n * n * n;
}

long long cubrt(long long n) {
    if (n == 1) {
        return 1;
    }

    long long l = 1, r = 5e5;

    long long ans = 1;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (mid * mid * mid <= n) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}

long long emulate(long long n) {
    long long ans = 0;

    while (n > 0) {
        long long rt = cubrt(n);

        long long val = rt * rt * rt;

        ans += n / val;
        n %= val;
    }

    return ans;
}

long long f(long long n) {
    return n * n * n - 1;
}

long long m;

pair <long long, long long> solve(long long m) {
    long long ans = emulate(m), ansX = m;

    if (m <= 100) {
        for (int i = 1; i <= m; i++) {
            long long val = emulate(i);
            if (val > ans || (val == ans && i > ansX)) {
                ans = val;
                ansX = i;
            }
        }

        return make_pair(ans, ansX);
    }

    for (long long rt = 1; cube(rt) <= m; rt++) {
        long long rangeR = min(m, cube(rt + 1) - 1) - cube(rt);

        pair <long long, long long> temp(solve(rangeR));

        long long cnt = 
    }

    return make_pair(ans, ansX);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%lld", &m);

    pair <long long, long long> ans(solve(m));
    
    printf("%lld %lld\n", ans.first, ans.second);

    return 0;
}
