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

int n, m, ans;
vector <int> g[MAXN];
int a[MAXN];

void dfs(int v, int cnt = 0, int par = 0) {
    bool leaf = true;

    if (a[v] == 0) {
        cnt = 0;
    } else {
        cnt++;
    }

    if (cnt > m) {
        return;
    }

    for (auto to: g[v]) {
        if (to == par) {
            continue;
        }

        dfs(to, cnt, v);
        leaf = false;
    }

    if (leaf) {
        ans++;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1);

    printf("%d\n", ans);
    
    return 0;
}
