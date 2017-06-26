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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, a[MAXN], b[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if (a[i] != b[i]) {
            cout << "rated" << endl;
            return 0;
        }
    }

    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            cout << "unrated" << endl;
            return 0;
        }
    }

    cout << "maybe" << endl;
    
    return 0;
}
