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

int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int m, d;
    cin >> m >> d;
    m--, d--;

    int ans = 1;

    for (int i = 0; i < days[m] - 1; i++) {
        d = (d + 1) % 7;
        if (d == 0) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
