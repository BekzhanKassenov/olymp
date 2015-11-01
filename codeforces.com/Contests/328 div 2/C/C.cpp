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

ull t, w, b;

ull gcd(ull a, ull b) {
    while (a > 0 && b > 0) {
        a %= b;
        swap(a, b);
    }

    return a + b;
}

void print(ull num, ull den) {
    if (num == 0) {
        cout << "0/1" << endl;
        return;
    }

    ull g = gcd(num, den);
    cout << (num / g) << '/' << (den / g) << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> t >> w >> b;

    ull g = gcd(w, b);

    if (log(w) + log(b) <= log(t) - log(g)) {
        ull lcm = w / g * b;

        ull ans = (t / lcm) * min(w, b) - 1;
        ans += min(t % lcm + 1, min(w, b));

        print(ans, t);
    } else {
        print(min(t, min(w, b) - 1), t);
    }

    return 0;
}
