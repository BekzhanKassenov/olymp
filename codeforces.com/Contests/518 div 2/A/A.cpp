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

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    long long n, m, k, l;
    cin >> n >> m >> k >> l;

    long long cnt = (k + l + m - 1) / m;

    if (k + l > n) {
        cout << -1 << endl;
        return 0;
    }

    if (cnt > n / m) {
        cout << -1 << endl;
        return 0;
    }

    cout << cnt << endl;
    
    return 0;
}
