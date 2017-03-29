/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <bits/stdc++.h>

using namespace std;

#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const long long INF = 1e18;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
long long a[MAXN];
long long s[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        s[i] = abs(a[i] - a[i + 1]);
        if (!(i & 1)) {
            s[i] *= -1;
        }
    }

    long long mx = 0, mn = 0;
    long long ans = s[1];
    for (int i = n - 1; i >= 0; i--) {
        s[i] += s[i + 1];
        if (s[i] > mx) {
            mx = s[i];
        }

        if (s[i] < mn) {
            mn = s[i];
        }

        if (!(i & 1)) {
            ans = max(ans, mx - s[i]);
        } else {
            ans = max(ans, s[i] - mn);
        }
    }

    cout << ans << endl;

    return 0;
}
