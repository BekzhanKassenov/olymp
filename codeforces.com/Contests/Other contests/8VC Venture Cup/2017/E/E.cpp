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

int n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n >> k;

    if (n < 4) {
        cout << -1 << endl;
        return 0;
    }

    if (k == 1 || k > 3 || (k == 2 && n == 4)) {
        cout << -1 << endl;
        return 0;
    }

    if (k == 2) {
        cout << n - 1 << endl;
        for (int i = 1; i + 1 <= n; i++) {
            cout << i << ' ' << i + 1 << endl;
        }

        return 0;
    }

    vector <pair <int, int> > ans;
    ans.emplace_back(1, 2);
    ans.emplace_back(n - 1, n);

    for (int i = 2; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans.emplace_back(i, j);
        }
    }

    cout << ans.size() << endl;
    for (const auto& p : ans) {
        cout << p.first << ' ' << p.second << endl;
    }

    return 0;
}
