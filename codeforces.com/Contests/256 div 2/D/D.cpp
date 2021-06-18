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
const int maxn = 500010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

long long n, m;
long long k;

long long solve(long long num) {
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += min(m, (num - 1) / i);
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n >> m >> k;
    if (n > m) swap(n, m);

    long long l = 1, r = n * m;
    long long ans = 0;
    while (l <= r) {
        long long mid = (l + r) / 2;
        long long pos = solve(mid);
        if (pos < k) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
