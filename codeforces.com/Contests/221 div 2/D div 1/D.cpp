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

int t[MAXN];

void add(int pos, int val) {
    for (int i = pos; i < MAXN; i |= i + 1) {
        t[i] += val;
    }
}

int sum(int pos) {
    int ans = 0;
    for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
        ans += t[i];
    }

    return ans;
}

int sum(int l, int r) {
    if (l == 0) {
        return sum(r);
    }

    return sum(r) - sum(l - 1);
}


// sack
int cnt[MAXN];

int n, m;
vector <int> g[MAXN];
vector <pair <int, int> > query[MAXN];
int qans[MAXN];
int color[MAXN];
int size[MAXN];

int tin[MAXN], tout[MAXN];
int atTin[MAXN], timer;

int biggest[MAXN];

void dfsPrep(int v, int p = 0) {
    tin[v] = timer++;
    atTin[tin[v]] = v;
    size[v] = 1;

    biggest[v] = -1;
    for (int to : g[v]) {
        if (to != p) {
            dfsPrep(to, v);
            size[v] += size[to];
            if (biggest[v] == -1 || size[to] > size[biggest[v]]) {
                biggest[v] = to;
            }
        }
    }

    tout[v] = timer;
}

void addSack(int color, int val) {
    add(cnt[color], -1);
    cnt[color] += val;
    add(cnt[color], 1);
}

void dfsAns(int v, int p = 0, bool keep = false) {
    for (int to : g[v]) {
        if (to != p && to != biggest[v]) {
            dfsAns(to, v, false);
        }
    }

    if (biggest[v] != -1) {
        dfsAns(biggest[v], v, true);
    }

    addSack(color[v], 1);
    for (int to : g[v]) {
        if (to != p && to != biggest[v]) {
            for (int _time = tin[to]; _time < tout[to]; _time++) {
                int ver = atTin[_time];
                addSack(color[ver], 1);
            }
        }
    }

    for (const auto& q : query[v]) {
        qans[q.second] = sum(q.first, MAXN - 1);
    }

    if (!keep) {
        for (int _time = tin[v]; _time < tout[v]; _time++) {
            int ver = atTin[_time];
            addSack(color[ver], -1);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &color[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 0; i < m; i++) {
        int v, k;
        scanf("%d%d", &v, &k);
        query[v].emplace_back(k, i);
    }

    dfsPrep(1);

    dfsAns(1);

    for (int i = 0; i < m; i++) {
        printf("%d\n", qans[i]);
    }

    return 0;
}
