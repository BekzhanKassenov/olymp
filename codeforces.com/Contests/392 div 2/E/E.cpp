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

struct Edge {
    int from, to;
    long long w, p;

    int other(int v) {
        if (v == from) {
            return to;
        }

        return from;
    }
};

Edge e[MAXN];

int n;
vector <int> g[MAXN];
vector <pair <int, int> > leafs[MAXN];
int par[MAXN];
int chdeg[MAXN];
long long sum[MAXN];
long long nsum[MAXN];

void merge(vector <pair <int, int> >& a, vector <pair <int, int> >& b) {
    if (a.size() < b.size()) {
        a.swap(b);
    }

    a.reserve(a.size() + b.size());
    for (const auto& x : b) {
        a.emplace_back(x);
    }
}

bool dfs(int v, int p = -1) {
    par[v] = p;

    int mx = -1;
    for (int idx : g[v]) {
        if (idx == p) {
            continue;
        }
        
        int to = e[idx].other(v);
        if (!dfs(to, idx)) {
            return false;
        }
        
        while (e[idx].p < sum[to] && !leafs[to].empty()) {
            auto p = leafs[to].back();
            int eidx = p.second;
            
            long long val = min(min(e[eidx].w - 1, e[eidx].p - nsum[p.first]), sum[to] - e[idx].p);
            sum[to] -= val;
            e[eidx].w -= val;
            e[eidx].p -= val;
            
            if (e[eidx].w == 1 || e[eidx].p == nsum[p.first]) {
                leafs[to].pop_back();
                int parent = e[eidx].other(p.first);
                chdeg[parent]--;
                nsum[parent] += nsum[p.first] + e[eidx].w;
                if (chdeg[parent] == 0 && parent != to) {
                    leafs[to].emplace_back(parent, par[parent]);
                }
            }
        }

        if (e[idx].p < sum[to]) {
            return false;
        }

        if (chdeg[to] == 0) {
            leafs[to].emplace_back(to, par[to]);
        }
    }

    for (int idx : g[v]) {
        if (idx == p) {
            continue;
        }

        int to = e[idx].other(v);
        sum[v] += sum[to] + e[idx].w;
        if (mx == -1 || leafs[mx].size() < leafs[to].size()) {
            mx = to;
        }
    }

    if (mx != -1) {
        leafs[v].swap(leafs[mx]);
    }

    for (int idx : g[v]) {
        if (idx == p) {
            continue;
        }

        int to = e[idx].other(v);
        if (to != mx) {
            merge(leafs[v], leafs[to]);
        }
    }
    
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d%lld%lld", &e[i].from, &e[i].to, &e[i].w, &e[i].p);
        g[e[i].from].push_back(i);
        g[e[i].to].push_back(i);
    }

    chdeg[1] = g[1].size();
    for (int i = 2; i <= n; i++) {
        chdeg[i] = g[i].size() - 1;
    }

    if (!dfs(1)) {
        puts("-1");
        return 0;
    }

    printf("%d\n", n);
    for (int i = 0; i < n - 1; i++) {
        printf("%d %d %lld %lld\n", e[i].from, e[i].to, e[i].w, e[i].p);
    }

    return 0;
}
