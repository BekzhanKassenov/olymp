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

int n, m, x, y;
int size[MAXN], dp[MAXN], rest[MAXN];
int tin[MAXN], fup[MAXN], timer;
bool used[MAXN];
vector <int> g[MAXN];

void dfs(int v, int par = -1) {
    used[v] = true;
    size[v] = 1;
    rest[v] = n - 1;

    tin[v] = fup[v] = timer++;

    for (int& to: g[v]) {

        if (to == par) {
            continue;
        }

        if (used[to]) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            dfs(to, v);

            size[v] += size[to];
            fup[v] = min(fup[v], fup[to]);

            if (fup[to] >= tin[v]) {
                rest[v] -= size[to];
                dp[v] = max(dp[v], size[to]);
            }
        }
    }
}


int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(3);

    int ans = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i], rest[i]);
        if (dp[i] < dp[ans]) {
            ans = i;
        }
    }

    printf("%d\n", ans);

    return 0;
}
