/****************************************
**          Solution by NU #1          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

#ifdef Local
# define I64 "%I64d"
#else
# define I64 "%Ld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const long long INF = 1e18;
const int MAXN = 4010;
const int VENIK = 2000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}


int main() {
    srand(time(NULL));

    int n = 4000;
    cout << n << endl;

    cout << MOD - 7;
    for (int i = 2; i < VENIK; i++) {
        cout << ' ' << 1;
    }

    cout << ' ' << MOD - 7;

    for (int i = VENIK + 1; i <= 4000; i++) {
        cout << ' ' << 1;
    }
    cout << endl;

    for (int i = 2; i <= VENIK; i++) {
        cout << i - 1 << ' ';
    }

    for (int i = VENIK + 1; i <= 4000; i++) {
        cout << 2000 << ' ';
    }

    return 0;
}
