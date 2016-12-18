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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, k;
int c[MAXN];
vector <int> g[MAXN];
bool used[MAXN];

void dfs(int v, map <int, int>& cnt) {
    cnt[c[v]]++;
    used[v] = true;

    for (int to: g[v]) {
        if (!used[to]) {
            dfs(to, cnt);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &m, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = 0;
    map <int, int> cnt;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i, cnt);

            int mx = 0;
            int sum = 0;
            for (const auto& it: cnt) {
                mx = max(mx, it.second);
                sum += it.second;
            }
            
            ans += sum - mx;
            cnt.clear();
        }
    }

    printf("%d\n", ans);

    return 0;
}
