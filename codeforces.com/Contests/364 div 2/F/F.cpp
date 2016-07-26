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
const int MAXN = 1010;
const int MAXM = 30010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
vector <int> g[MAXN];

bool used[MAXN];
int tin[MAXN], tout[MAXN], fup[MAXN];
int parent[MAXN];
int timer;

int from[MAXM], to[MAXM], cost[MAXM];
int lastEdge, blockedEdge = -1;
bool isBridge[MAXM];

int getTo(int idx, int v) {
    if (v == from[idx]) {
        return to[idx];
    }

    return from[idx];
}

void dfs(int v) {
    used[v] = true;
    fup[v] = tin[v] = timer++;

    for (int idx: g[v]) {
        if (idx == blockedEdge || idx == parent[v]) {
            continue;
        }

        int dest = getTo(idx, v);

        if (!used[dest]) {
            parent[dest] = idx;
            dfs(dest);
            fup[v] = min(fup[v], fup[dest]);

            if (tin[v] < fup[dest]) {
                isBridge[idx] = true;
            }
        } else {
            fup[v] = min(fup[v], tin[dest]);
        }
    }

    tout[v] = timer++;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    int s, t;
    scanf("%d%d", &s, &t);

    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &from[lastEdge], &to[lastEdge], &cost[lastEdge]);
        g[from[lastEdge]].push_back(lastEdge);
        g[to[lastEdge]].push_back(lastEdge);
        lastEdge++;
    }

    parent[s] = -1;
    dfs(s);
    if (!used[t]) {
        puts("0");
        puts("0");
        return 0;
    }

    vector <int> edges;
    int v = t;
    while (v != s) {
        edges.push_back(parent[v]);
        v = getTo(parent[v], v);
    }

    int ansCost = INF + 100;
    vector <int> ans;
    
    for (int idx: edges) {
        if (isBridge[idx] && cost[idx] < ansCost) {
            ansCost = cost[idx];
            ans = {idx + 1};
        }
    }

    for (int idx: edges) {
        blockedEdge = idx;
        memset(used, false, sizeof used);
        memset(isBridge, false, sizeof isBridge);
        memset(parent, 255, sizeof parent);
        timer = 0;

        dfs(s);

        if (!used[t]) {
            continue;
        }

        int v = t;
        while (v != s) {
            if (isBridge[parent[v]] && cost[parent[v]] + cost[idx] < ansCost) {
                ansCost = cost[parent[v]] + cost[idx];
                ans = {idx + 1, parent[v] + 1};
            }

            v = getTo(parent[v], v);
        }
    }

    if (ansCost == INF + 100) {
        puts("-1");
        return 0;
    }

    printf("%d\n", ansCost);
    printf("%d\n", (int)ans.size());
    for (int x: ans) {
        printf("%d ", x);
    }

    puts("");

    return 0;
}
