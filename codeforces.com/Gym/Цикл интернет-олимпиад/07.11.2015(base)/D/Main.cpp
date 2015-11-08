/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "lcm"

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

long long gcd(long long a, long long b) {
    while (a && b) {
         a %= b;
         swap(a, b);
    }

    return a + b;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int T;
long long a, b;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &T);

    while (T--) {
        scanf("%I64d%I64d", &a, &b);

        long long ans = 0;
        do {
            ans = max(ans, lcm(a, b));

            if (gcd(a, b) == 1) {
                break;
            }
        } while (b--);

        printf("%I64d\n", ans);
    }

    return 0;
}