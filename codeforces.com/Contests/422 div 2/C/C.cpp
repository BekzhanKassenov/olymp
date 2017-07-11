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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, x;
int l[MAXN], r[MAXN], cost[MAXN];
vector <int> open[MAXN], close[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &l[i], &r[i], &cost[i]);
        open[l[i]].push_back(i);
        close[r[i]].push_back(i);
    }

    int ans = -1;
    map <int, int> best;
    for (int i = 0; i < MAXN; i++) {
        for (int idx : open[i]) {
            int len = r[idx] - l[idx] + 1;
            int expect = x - len;
            if (best.count(expect) && (ans == -1 || best[expect] + cost[idx] < ans)) {
                ans = best[expect] + cost[idx];
            }
        }

        for (int idx : close[i]) {
            int len = r[idx] - l[idx] + 1;
            if (!best.count(len) || best[len] > cost[idx]) {
                best[len] = cost[idx];
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}
