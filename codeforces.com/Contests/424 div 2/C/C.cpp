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
const int MAXN = 2010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int k, n;
int a[MAXN], b[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int cur = 0;
    vector <int> vec;
    
    for (int i = 0; i < k; i++) {
        cur += a[i];
        vec.push_back(cur);
    }

    sort(all(vec));
    vec.resize(unique(all(vec)) - vec.begin());
    k = vec.size();

    int ans = 0;
    for (int i = k - 1; i >= 0; i--) {
        bool ok = true;
        for (int j = n - 2; j >= 0; j--) {
            int delta = b[n - 1] - b[j];
            int num = vec[i] - delta;
            if (!binary_search(all(vec), num)) {
                ok = false;
            }
        }

        ans += ok;
    }

    cout << ans << endl;

    return 0;
}
