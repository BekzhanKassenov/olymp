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
long long ans = 0;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    ans = n - 2;
    for (int i = 2; i <= n; i++) {
        int prev = i - 2;
        if (prev >= 2) {
            ans += prev - 2 + 1;
        }

        int next = i + 2;
        if (next <= n) {
            ans += n - next + 1;
        }
    }

    printf("%I64d\n", ans);

    return 0;
}
