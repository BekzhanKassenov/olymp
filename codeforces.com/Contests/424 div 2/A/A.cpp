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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, a[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n && a[j] == a[i]; j++) {
            bool ok1 = true, ok2 = true;
            for (int k = 1; k <= i; k++) {
                if (a[k] <= a[k - 1]) {
                    ok1 = false;
                }
            }
            for (int k = j + 1; k < n; k++) {
                if (a[k] >= a[k - 1]) {
                    ok2 = false;
                }
            }
            if (ok1 && ok2) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    
    cout << "NO" << endl;

    return 0;
}
