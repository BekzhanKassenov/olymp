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

double a[4];

double det(double a[]) {
    return a[0] * a[3] - a[1] * a[2];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> a[0] >> a[1] >> a[2] >> a[3];

    cout << fixed << setprecision(11);

    if (det(a) == 0) {
        puts("0");
        return 0;
    }

    double res = 1e100;

    for (int mask = 0; mask < (1 << 4); mask++) {
        int bitcnt = __builtin_popcount(mask);
        
        if (bitcnt != 0 && bitcnt != 2 && bitcnt != 4) {
            continue;
        }
        
        double temp = 0;

        for (int i = 0; i < 4; i++) {
            if (mask & (1 << i)) {
                temp += a[i];
            } else {
                temp -= a[i];
            }
        }

        if (temp != 0) {
            res = min(res, abs(det(a) / temp));
        }
    }

    cout << res << endl;

    return 0;
}
