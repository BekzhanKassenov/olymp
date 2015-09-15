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

int n, m, k;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &m, &k);
    
    if (n % 2 == 0) {
        puts("Marsel");
        return 0;
    }

    for (int i = 2; i * i <= m; i++) {
        if (m % i == 0) {
            if (i >= k || m / i >= k) {
                puts("Timur");
                return 0;
            }
        }
    }

    if (k == 1 && m != 1) {
        puts("Timur");
        return 0;
    }
    
    puts("Marsel");

    return 0;
}
