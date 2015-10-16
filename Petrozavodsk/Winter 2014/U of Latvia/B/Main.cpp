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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k;
vector <int> g1[MAXN], g2[MAXN];
bool used[MAXN];
vector <vector <int> > ans;
vector <int> order;

void dfs1(int v) {
    used[v] = true;
    for (int to: g1[v]) {
        if (!used[to]) {
            dfs1(to);
        }
    }

    order.push_back(v);
}

void dfs2(int v, vector <int>& comp) {
    comp.push_back(v);
    used[v] = true;

    for (int to: g2[v]) {
        if (!used[to]) {
            dfs2(to, comp);
        }
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        int size;
        scanf("%d", &size);

        int x;
        scanf("%d", &x);

        for (int j = 1; j < size; j++) {
            int y;
            scanf("%d", &y);
            g1[x].push_back(y);
            g2[y].push_back(x);
            x = y;
        }
    }

    for (int i = 1; i <= k; i++) {
        if (!used[i]) {
            dfs1(i);
        }
    }

    reverse(all(order));

    memset(used, false, sizeof used);
    for (int v: order) {
        if (!used[v]) {
            vector <int> comp;
            dfs2(v, comp);
            ans.push_back(comp);
        }
    }

    printf("%u\n", ans.size());

    for (auto& comp: ans) {
        printf("%u", comp.size());

        for (int v: comp) {
            printf(" %d", v);
        }
        puts("");
    }

    return 0;
}
