#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <utility>
#include <cassert>

#define fname ""
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef vector <int> VI;

const int maxn = 3000 * 100 + 100;
const int inf = 2 * 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;
const int maxpw = 18;

int n, m, a[maxn], b[maxn], ans, cnt[maxn], t[4 * maxn];
int pos[maxn], p[maxn][20], in[maxn], out[maxn], Time, Pos;
vector <int> g[maxn];
pair <PII, PII> s[maxn];
bool need[4 * maxn];

int get(int v, int tl, int tr, int l) {
    if (tl == tr)
        return t[v];
    int mid = (tl + tr) / 2;

    if (l <= mid)
        return max(t[v], get(v + v, tl, mid, l));  
    else
        return max(t[v], get(v + v + 1, mid + 1, tr, l));
}

void upd(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
        t[v] = 1;
        return;
    }

    int mid = (tl + tr) / 2;

    if (l <= mid)
        upd(v + v, tl, mid, l, min(mid, r));
    if (r >= mid + 1)
        upd(v + v + 1, mid + 1, tr, max(mid + 1, l), r);

    return;
}

bool check(int u, int v) {
    if (in[u] <= in[v] && out[u] >= out[v])
        return true;
    return false;
}

int lca(int u, int v) {
    if (check(u, v))
        return u;
    if (check(v, u))
        return v;

    for (int i = maxpw; i >= 0; --i)
        while (p[u][i] && !check(p[u][i], v))
            u = p[u][i];
        
    return p[u][0];
}

int dfs(int v, int par) {
    int to;
    in[v] = ++Time;
    pos[v] = ++Pos;
    cnt[v]++;
    p[v][0] = par;

    for (int i = 1; i <= maxpw; ++i)
        p[v][i] = p[p[v][i - 1]][i - 1];

    for (int i = 0; i < (int)g[v].size(); ++i) {
        to = g[v][i];

        if (to == par)
            continue;

        cnt[v] += dfs(to, v);
    }

    out[v] = ++Time;
    return cnt[v];
}

int main() {
    freopen(fname"in", "r", stdin);
//  freopen(fname"out", "w", stdout);

    scanf("%d%d", &n, &m);
    
    int u, v, w;
    
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1, 0);

    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &s[i].S.F, &s[i].S.S);
        w = lca(s[i].S.F, s[i].S.S);
        s[i].F.F = in[w];
        s[i].F.S = w;
    }

    sort(s, s + m);
    reverse(s, s + m);

    int Left, Right;
    
    for (int i = 0; i < m; ++i) {
        a[i] = pos[s[i].S.F];
        b[i] = pos[s[i].S.S];
        if (!get(1, 1, n, a[i]) && !get(1, 1, n, b[i])) {
            Left = pos[s[i].F.S];
            Right = Left + cnt[s[i].F.S] - 1;
            upd(1, 1, n, Left, Right);
            ++ans;
        }
    }

    printf("%d\n", ans);

    return 0;
}