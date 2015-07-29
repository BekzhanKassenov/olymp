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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int parent[MAXN];
int size[MAXN];

int get(int v) {
    if (v == parent[v]) {
        return v;
    }

    return parent[v] = get(parent[v]);
}

void unite(int a, int b) {
    a = get(a);
    b = get(b);

    if (a == b) {
        return;
    }

    if (size[a] > size[b]) {
        parent[b] = a;
        size[a] += size[b];
    } else {
        parent[a] = b;
        size[b] += size[a];
    }
}

int n, m, p;
int q[MAXN], x, y;
pair <int, int> t[MAXN];
int ans[MAXN];
bool added[MAXN];
vector <int> g[MAXN];
int mx = -1;

bool cmp(const pair <int, int>& a, const pair <int, int>& b) {
    return a.first < b.first;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d%d", &n, &m, &p);
    
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    
    t[0] = make_pair(INF, 0);
    for (int i = 1; i < n; i++) {
       scanf("%d", &t[i].first);
       t[i].second = i;
    }

    for (int i = 0; i < p; i++) {
        scanf("%d", &q[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    sort(t, t + n, cmp);

    for (int i = n - 1; i >= 0; i--) {
        int v = t[i].second;
        added[v] = true;

        for (size_t j = 0; j < g[v].size(); j++) {
            int to = g[v][j];
            if (added[to]) {
                unite(v, to);
            }
        }

        ans[i] = size[get(0)];
    }

    for (int i = 0; i < p; i++) {
        pair <int, int> to_search(q[i], 0);
        int pos = lower_bound(t, t + n, to_search, cmp) - t;

        if (pos > mx) {
            mx = pos;
        } else {
            pos = mx;
        }

        printf("%I64d\n", 1ll * ans[pos] * q[i]); 
    }
    
    return 0;
}
