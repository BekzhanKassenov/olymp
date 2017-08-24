/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <bits/stdc++.h>

using namespace std;

#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 60;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int a[MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    ull ans = 0;
    for (int i = 0; i < n; i++) {
        int cnt0 = 0, cnt1 = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                cnt0++;
            } else {
                cnt1++;
            }
        }

        if (cnt0 > 1) {
            ans += (1ull << cnt0) - cnt0 - 1;
        }

        if (cnt1 > 1) {
            ans += (1ull << cnt1) - cnt1 - 1;
        }
    }

    for (int j = 0; j < m; j++) {
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][j] == 0) {
                cnt0++;
            } else {
                cnt1++;
            }
        }

        if (cnt0 > 1) {
            ans += (1ull << cnt0) - cnt0 - 1;
        }

        if (cnt1 > 1) {
            ans += (1ull << cnt1) - cnt1 - 1;
        }
    }

    ans += n * m;
    cout << ans << endl;
    
    return 0;
}
