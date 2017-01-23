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

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int n, m, k;
    cin >> n >> m >> k;

    if (m == n) {
        cout << 1 << endl;
        return 0;
    }

    m -= n + 1;
    int ans = 2;
    int l = max(k - 1, 1), r = min(k + 1, n);

    while ((l > 1 || r < n) && m >= (r - l + 1)) {
        m -= r - l + 1;
        ans++;

        if (l > 1) {
            l--;
        }

        if (r < n) {
            r++;
        }
    }

    int len = r - l + 1;
    ans += m / len;

    cout << ans << endl;

    return 0;
}
