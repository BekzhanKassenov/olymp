/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "kingdom"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100000 + 13;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
vector <int> g[MAXN];
vector <pair <int, int> > ans;
vector <int> leafs;

void dfs(int v, int p = -1) {
    if (g[v].size() == 1u) {
        leafs.push_back(v);
        return;
    }
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
        }
    }
}

int main() {
    freopen(File".in", "r", stdin);
#ifndef Local
    freopen(File".out", "w", stdout);
#endif
    
    scanf("%d", &n);

    int from, to;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &from, &to);
        g[from].push_back(to);
        g[to].push_back(from);
    }

    if (n == 2) {
        puts("1");
        puts("1 2");
        return 0;
    }

    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() > 1u) {
            root = i;
            break;
        }
    }

    dfs(root);

    int m = leafs.size() / 2;
    for (size_t i = 0; i < m; i++) {
        ans.emplace_back(leafs[i], leafs[i + m]);
    }
    if (leafs.size() % 2 == 1) {
        ans.emplace_back(leafs[0], leafs.back());
    }
 
    printf("%u\n", ans.size());
    for (auto p: ans) {
        printf("%d %d\n", p.first, p.second);
    }

    return 0;
}
