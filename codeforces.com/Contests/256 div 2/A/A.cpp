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

int n, a, b, x;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    for (int i = 0; i < 3; i++) {
        scanf("%d", &x);
        a += x;
    }

    for (int i = 0; i < 3; i++) {
        scanf("%d", &x);
        b += x;
    }

    scanf("%d", &n);
    
    puts((a + 4) / 5 + (b + 9) / 10 <= n ? "YES" : "NO");

    return 0;
}
