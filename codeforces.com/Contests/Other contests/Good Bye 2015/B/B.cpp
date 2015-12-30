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

ull a, b;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%I64u%I64u", &a, &b);

    int ans = 0;
    for (int len = 1; len <= 62; len++) {
        for (int pos = 0; pos < len - 1; pos++) {
            ull num = (1ll << len) - 1;
            num ^= 1ll << pos;

            if (a <= num && num <= b) {
                ans++;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
