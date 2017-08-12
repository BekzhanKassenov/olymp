/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <bits/stdc++.h>

using namespace std;

#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const double EPS = 1e-12;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
vector <int> g[MAXN];
long double ans;

void dfs(int v, long double den, int d, int par = 0) {
    if (par != 0 && den * d < EPS) {
        den = 0;
    }

    int cnt = (int)g[v].size() - (par != 0);
    if (cnt == 0) {
        ans += den * d;
    } else {
        for (int to : g[v]) {
            if (to != par) {
                dfs(to, den / cnt, d + 1, v);
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 1.0, 0);

    cout << fixed << setprecision(14) << ans << endl;
    
    return 0;
}
