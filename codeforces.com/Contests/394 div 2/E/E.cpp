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
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int MAXN = 32;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
vector <int> g[MAXN];
long long X[MAXN], Y[MAXN];

void dfs(int v, long long x, long long y, long long add, int par = 0, int blocked = -1) {
    X[v] = x, Y[v] = y;

    int pos = 0;
    for (int to : g[v]) {
        if (to == par) {
            continue;
        }
        while (pos == blocked) {
            pos = (pos + 1) % 4;
        }

        dfs(to, x + (add + 1) * dx[pos], y + (add + 1) * dy[pos], add >> 1, v, (pos + 2) % 4);
        pos = (pos + 1) % 4;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (g[i].size() > static_cast<size_t>(4)) {
            cout << "NO" << endl;
            return 0;
        }
    }

    dfs(1, 0, 0, 1ll << 32);

    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
        cout << X[i] << ' ' << Y[i] << endl;
    }

    return 0;
}
