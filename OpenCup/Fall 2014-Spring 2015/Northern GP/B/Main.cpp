/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "borderless"

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

int n;

bool check(int mask) {
    for (int len = 1; len < n; len++) {
        bool eq = true;
        for (int i = 0; i < len; i++) {
            if (((mask >> i) & 1) != ((mask >> (n - len + i)) & 1)) {
                eq = false;
            }
        }

        if (eq) {
            return false;
        }
    }

    return true;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    cin >> n;

    check((1 << n) - 1);

    for (int mask = 0; mask < (1 << n); mask++) {
        if (check(mask)) {
            for (int i = n - 1; i >= 0; i--) {
                putchar('a' + ((mask & (1 << i)) > 0));
            }
            putchar('\n');
        }
    }

    return 0;
}
