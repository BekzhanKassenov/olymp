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

struct Query {
    int type, a, b;
};

Query q[MAXN];
int DSUparent[MAXN];
int tin[MAXN], tout[MAXN], timer;
int n, m;
bool root[MAXN];
vector <int> child[MAXN];
pair <int, int> doc[MAXN];
int last = 1;

void dfs(int v) {
    tin[v] = timer++;

    for (size_t i = 0; i < child[v].size(); i++)
        dfs(child[v][i]);

    tout[v] = timer++;
}

bool ancestor(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int DSUget(int v) {
    if (DSUparent[v] == v)
        return v;

    return DSUparent[v] = DSUget(DSUparent[v]);
}

void DSUunion(int a, int b) {
    a = DSUget(a);
    b = DSUget(b);
    DSUparent[a] = b;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
                       
    memset(root, true, sizeof root);

    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &q[i].type, &q[i].a);
        if (q[i].type == 1 || q[i].type == 3)
            scanf("%d", &q[i].b);

        if (q[i].type == 1) {
            child[q[i].b].push_back(q[i].a);
            root[q[i].a] = false;
        }
    }

    for (int i = 1; i <= n; i++)
        DSUparent[i] = i;

    for (int i = 1; i <= n; i++)
        if (root[i])
            dfs(i);

    for (int i = 1; i <= m; i++) {
        if (q[i].type == 1) {
            DSUunion(q[i].a, q[i].b);
        } else if (q[i].type == 2) {
            int par = DSUget(q[i].a);
            doc[last++] = make_pair(par, q[i].a);
        } else {
            int par = doc[q[i].b].first;
            int child = doc[q[i].b].second;

            if (ancestor(par, q[i].a) && ancestor(q[i].a, child))
                puts("YES");
            else
                puts("NO");
        }
    }

    return 0;
}
