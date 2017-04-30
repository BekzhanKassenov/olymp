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
const int INF = 2000 * 1000 + 100;
const int MAXN = 85;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k, m;
vector <pair <int, int> > g[MAXN];
int dp[MAXN][MAXN][MAXN][2];
bool calced[MAXN][MAXN][MAXN][2];

int go(int l, int r, bool is_left, int depth) {
    if (calced[l][r][depth][is_left]) {
        return dp[l][r][depth][is_left];
    }

    calced[l][r][depth][is_left] = true;

    int& ans = dp[l][r][depth][is_left];
    if (depth >= k) {
        return ans = 0;
    }

    ans = INF;
    if (is_left) {
        for (const auto& p : g[l]) {
            int to = p.first;
            int cost = p.second;
            if (l < to && to <= r) {
                ans = min(ans, go(l + 1, to, false, depth + 1) + cost);
                ans = min(ans, go(to, r, true, depth + 1) + cost);
            }
        }
    } else {
        for (const auto& p : g[r]) {
            int to = p.first;
            int cost = p.second;
            if (l <= to && to < r) {
                ans = min(ans, go(l, to, false, depth + 1) + cost);
                ans = min(ans, go(to, r - 1, true, depth + 1) + cost);
            }
        }
    }
    if (ans > INF) {
        ans = INF;
    }

    //cout << l << ' ' << r << ' ' << is_left << ' ' << depth << ' ' << ans << endl;

    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n >> k >> m;
    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        g[u].emplace_back(v, cost);
    }

    int ans = INF;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, go(1, i, false, 1));
        ans = min(ans, go(i, n, true, 1));
    }

    if (ans == INF) {
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;
    
    return 0;
}
