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

    int l, r;
    cin >> l >> r;

    if (l == r) {
        map <int, int> cnt;
        for (int i = 2; i * i <= l; i++) {
            if (l % i == 0) {
                cnt[i]++;
                if (i * i != l) {
                    cnt[l / i]++;
                }
            }
        }

        int ans = 2;
        for (const auto& x : cnt) {
            if (x.second > cnt[ans]) {
                ans = x.first;
            }
        }

        cout << ans << endl;
    } else {
        cout << 2 << endl;
    }
    
    return 0;
}
