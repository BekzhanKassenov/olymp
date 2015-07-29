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

long long n, ans, last = 1, cnt = 1;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%I64d", &n);

    for (long long i = 10; i <= n; i *= 10) {
        ans += (i - i / 10) * cnt;
        last = i;
        cnt++;
    }

    ans += (n - last + 1) * cnt;

    printf("%I64d\n", ans);

    return 0;
}
