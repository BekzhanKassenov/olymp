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

int a[3];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int n, x;
    cin >> n >> x;

    a[x] = 1;
    n--;
    n %= 6;

    while (n >= 0) {
        if (n & 1) {
            swap(a[1], a[2]);
        } else {
            swap(a[0], a[1]);
        }
        n--;
    }

    for (int i = 0; i < 3; i++) {
        if (a[i]) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}
