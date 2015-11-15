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

char neg(char c) {
    if (c == 'R') {
        return 'P';
    } else if (c == 'S') {
        return 'R';
    }

    return 'S';
}

long long n;

char solve(long long n) {
    if (n < 3) {
        switch (n) {
            case 0:
                return 'P';
            case 1:
                return 'S';
            case 2:
                return 'R';
            default:
                assert(false);
        }
    }

    long long base = 0, power = 1;

    while (3 * power <= n) {
        base++;
        power *= 3;
    }

    if (2 * power <= n) {
        return neg(neg(solve(n % power)));
    }

    return neg(solve(n % power));
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    while (scanf("%I64d", &n) == 1 && n != 0) {
        putchar(solve(n - 1));
        putchar('\n');
    }
    
    return 0;
}
