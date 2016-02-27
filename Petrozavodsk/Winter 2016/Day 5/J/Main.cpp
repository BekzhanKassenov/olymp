/****************************************
**          Solution by NU #2          **
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
const int MAXN = 10010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int parent[20];
vector <int> g[20];

int getParent(int v) {
    if (v == parent[v]) {
        return v;
    }

    return parent[v] = getParent(parent[v]);
}

void unite(int a, int b) {
    parent[getParent(a)] = getParent(b);
}

int dfs(int v, int sum = 0, int par = 0) {
    sum ^= v;
    int ans = sum == 0;

    for (int to: g[v]) {
        if (to != par) {
            ans += dfs(to, sum, v);
        }
    }

    return ans;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    if (n >= 17) {
        puts("Yes");
        for (int i = 1; i < n; i++) {
            printf("%d %d\n", i, i + 1);
        }

        return 0;
    } else if (n < 12) {
        puts("No");
        return 0;
    }

    vector <pair <int, int> > vec;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            vec.emplace_back(i, j);
        }
    }

    random_device rd;
    mt19937 gen(rd());
    
    while (true) {
        shuffle(all(vec), gen);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            g[i].clear();
        }

        vector <pair <int, int> > edges;
        for (const auto& edge: vec) {
            int u = edge.first;
            int v = edge.second;
            if (getParent(u) != getParent(v)) {
                unite(u, v);
                g[u].push_back(v);
                g[v].push_back(u);
                edges.emplace_back(u, v);
            }
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += dfs(i);
        }

        cerr << cnt << endl;

        if (n < cnt / 2) {
            puts("Yes");
            for (const auto& edge: edges) {
                printf("%d %d\n", edge.first, edge.second);
            }

            return 0;
        }
    }

    return 0;
}
