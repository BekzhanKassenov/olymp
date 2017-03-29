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
const int MAXN = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct edge : public pair <int, int> {
    int other(int v) {
        if (v == first) {
            return second;
        }

        return first;
    }
};

int n, m;  
vector <int> g[MAXN];
bool used[MAXN];
bool loop[MAXN];

bool dfs(int v) {
    used[v] = true;
    bool has_edge = loop[v];
    for (int to : g[v]) {
        has_edge = true;
        if (!used[to]) {
            dfs(to);
        }
    }

    return has_edge;
}

long long f(long long n) {
    return n * (n - 1) / 2;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    int loops = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);

        if (u != v) {
            g[u].push_back(v);
            g[v].push_back(u);
        } else {
            loops++;
            loop[v] = true;
        }
    }

    int comps = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i] && dfs(i)) {
            comps++;
        }
    }

    if (comps != 1 || m == 1) {
        puts("0");
        return 0;
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += f(g[i].size());
    }

    ans += f(loops);
    ans += 1ll * loops * (m - loops);

    printf("%lld\n", ans);

    return 0;
}
