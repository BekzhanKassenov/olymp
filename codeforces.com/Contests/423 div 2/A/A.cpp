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

    int n, a, b, c = 0;
    cin >> n >> a >> b;

    int ans = 0;
    while (n--) {
        int t;
        cin >> t;

        if (t == 1) {
            if (a > 0) {
                a--;
            } else if (b > 0) {
                b--;
                c++;
            } else if (c > 0) {
                c--;
            } else {
                ans++;
            }
        } else {
            if (b > 0) {
                b--;
            } else {
                ans += 2;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
