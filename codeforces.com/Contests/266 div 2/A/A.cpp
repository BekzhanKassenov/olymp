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

int n, m, a, b;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    scanf("%d%d%d%d", &n, &m, &a, &b);

    printf("%d\n", min(min(n * a, (n / m) * b + (n % m) * a), ((n + m - 1) / m) * b));

    return 0;
}
