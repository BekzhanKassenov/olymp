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

ll f(int n) {
    ll power = 1;
    ll sum = 0;
    int iter = 0;

    while (n) {
        int dig = n % 10;
        n /= 10;

        sum += dig;

        if (dig != 0) {
            if (iter)
                sum += power;
            
            sum += (dig * (dig - 1)) / 2 * power;
        }

        iter++;

        power *= 45;
    }

    return sum;
}

ll f_stup(int n) {
    ll res = 0;

    for (int i = 0; i <= n; i++) {
        int temp = i;

        while (temp) {
            res += temp % 10;
            temp /= 10;
        }
    }

    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    for (int i = 0; i < 20; i++)
        cout << f(i) << ' ' << f_stup(i) << endl;

    return 0;
}
