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

int n, k;
int a[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int arya = 0;
    int bran = 0;
    for (int i = 1; i <= n; i++) {
        arya += a[i];
        
        int to_give = min(8, arya);
        bran += to_give;
        arya -= to_give;

        if (bran >= k) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    
    return 0;
}
