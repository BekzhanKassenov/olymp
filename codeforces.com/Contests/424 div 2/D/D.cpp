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
const long long INF = 4000LL * 1000 * 1000 + 2000;
const int MAXN = 2010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k, p;
long long a[MAXN], b[MAXN];
bool dp[MAXN][MAXN];
bool can[MAXN][MAXN];

bool check(long long lim) {
    for (int i = 1; i <= k; i++) {
        dp[1][i] = ((abs(a[1] - b[i]) + abs(b[i] - p)) <= lim);
        can[1][i] = can[1][i - 1] || dp[1][i];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            long long dist = abs(a[i] - b[j]) + abs(p - b[j]);
            dp[i][j] = can[i - 1][j - 1] && dist <= lim;
            can[i][j] = can[i][j - 1] || dp[i][j];
        }
    }

    for (int i = 1; i <= k; i++) {
        if (dp[n][i]) {
            return true;
        }
    }

    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n >> k >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];        
    }

    for (int i = 1; i <= k; i++) {
        cin >> b[i];
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + k + 1);

    long long l = 0, r = INF;
    long long ans = -1;

    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
