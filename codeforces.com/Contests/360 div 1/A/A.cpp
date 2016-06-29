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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
vector <int> g[MAXN];
int color[MAXN];

bool dfs(int v, int c = 1) {
    color[v] = c;
    for (int to: g[v]) {
        if (color[to] == color[v]) {
            return false;
        }

        if (color[to] == 0 && !dfs(to, 3 - c)) {
            return false;
        }
    }

    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == 0 && !dfs(i)) {
            puts("-1");
            return 0;
        }
    }

    vector <int> ans1, ans2;

    for (int i = 1; i <= n; i++) {
        if (color[i] == 1) {
            ans1.push_back(i);
        } else {
            ans2.push_back(i);
        }
    }

    cout << ans1.size() << endl;
    for (int x: ans1) {
        printf("%d ", x);
    }

    puts("");

    cout << ans2.size() << endl;
    for (int x: ans2) {
        printf("%d ", x);
    }
             
    puts("");

    return 0;
}
