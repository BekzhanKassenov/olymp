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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int sum[MAXN];
bool prime[32];

bool isPrime(int n) {
    if (n == 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    for (int i = 0; i < 32; i++) {
        prime[i] = isPrime(i);
    }

    for (int i = 1; i < MAXN; i++) {
        sum[i] = sum[i - 1] + prime[__builtin_popcount(i)];
    }

    scanf("%d", &T);

    while (T--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", sum[r] - sum[max(l - 1, 0)]);
    }
    
    return 0;
}
