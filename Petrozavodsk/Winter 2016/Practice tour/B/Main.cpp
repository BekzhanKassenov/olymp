/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#ifdef Local
# define I64 "%I64d"
#else
# define I64 "%Ld"
#endif

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

long long a, b;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf(I64 I64, &a, &b);

    printf(I64, a * b);

    return 0;
}
