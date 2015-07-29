/******************************************
**          Solution by NU #2            **
******************************************/

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define MP make_pair
#define File "trees"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> PII;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double PI = acos(-1.0);

template <typename T>
inline T sqr(T x) {
    return (x * x);
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    int n;
    cin >> n;

    ll ans = 1;

    for (int i = 1; i < n; i++) {
        ans *= i;

        if (ans >= 1e12)
            ans %= MOD;
    }

    ans %= MOD;

    cout << ans;

    return 0;
}