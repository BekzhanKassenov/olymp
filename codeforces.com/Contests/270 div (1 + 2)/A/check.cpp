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

bool prime(int n) {
    if (n == 1 || n == 0)
        return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int n, k;

int main() {
#ifndef ONLINE_JUDGE
    freopen("out", "r", stdin);
#endif

    while (scanf("%d%d", &n, &k) == 1) {
        if (prime(n) || prime(k)) {
            cerr << n + k << endl;
            assert(false);
        }
    }
    
    return 0;
}
