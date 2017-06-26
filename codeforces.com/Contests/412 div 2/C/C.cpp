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
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

void solve(long long x, long long y, long long p, long long q) {
    if (p == 0) {
        if (x != 0) {
            cout << -1 << endl;
        } else {
            cout << 0 << endl;
        }
        return;
    }

    if (p == q) {
        if (x != y) {
            cout << -1 << endl;
        } else {
            cout << 0 << endl;
        }
        return;
    }
    
    p = q - p;
    long long S = x + y;
    long long kp = max((y + p - 1) / p - (S + q - 1) / q, 0ll);

    long long Sa = S % q + q * kp;

    cout << Sa << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    long long x, y, p, q;
    int T;
    cin >> T;

    while (T--) {
        cin >> x >> y >> p >> q;
        solve(x, y, p, q);
    }
    
    return 0;
}
