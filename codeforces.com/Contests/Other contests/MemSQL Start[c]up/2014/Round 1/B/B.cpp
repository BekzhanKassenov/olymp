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

int n, m;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    
    if (n == 0) {
        printf("0 1\n0 %d\n0 0\n0 %d", m, m - 1);
        return 0;
    }

    if (m == 0) {
        printf("1 0\n%d 1\n0 0\n%d 0", n, n - 1);
        return 0;
    }

    printf("%d %d\n%d %d\n", n, m, 0, 0);

    if (n < m) {
        printf("%d %d\n%d %d\n", 0, m, n, 0);
    } else {
        printf("%d %d\n%d %d\n", n, 0, 0, m);
    } 

    return 0;
}
