/****************************************
**          Solution by NU #2          **
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

int power(int n, int p) {
    int result = 1;
    while (p > 0) {
        if (p & 1) {
            result = (1ll * result * n) % MOD;
        }

        n = (1ll * n * n) % MOD;
        p >>= 1;
    }

    return result;
}

int inv(int n) {
    return power(n, MOD - 2);
}

int fact(int n) {
    if (n <= 0) {
        return 1;
    }

    return (1ll * fact(n - 1) * n) % MOD;
}

int n;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    int ans = fact(n - 2);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        sum += x;
        ans = (1ll * ans * inv(fact(x - 1))) % MOD;
    }

    if (sum != 2 * (n - 1)) {
        puts("0");
        return 0;
    }

    printf("%d\n", ans);

    return 0;
}
