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

string binary(int n) {
    string res;

    for (int i = 15; i >= 0; i--) {
        if (n & (1 << i))
            res += '1';
        else
            res += '0';
    }

    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int n;

    while (cin >> n) {
        cout << setw(5) << n << ' ' << binary(n) << " popcount: " << __builtin_popcount(n) << endl;
    }

    return 0;
}
