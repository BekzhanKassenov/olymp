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
const int MAXV = 60;
const int MAXE = 2010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct MaxFlow {
    int from[MAXE], to[MAXE];
    int flow[MAXE], cap[MAXE];
    int last;

    vector <int> g[MAXV];
    bool used[MAXV];

    void clear() {
        last = 0;

        for (int i = 0; i < MAXV; i++) {
            g[i].clear();
        }
    }

    MaxFlow() {
        clear();
    }

    void addEdge(int from, int to, int cap) {
        this->from[last] = from;
        this->to[last] = to;
        this->flow[last] = 0;
        this->cap[last] = cap;
        g[from].push_back(last++);

        this->from[last] = to;
        this->to[last] = from;
        this->flow[last] = 0;
        this->cap[last] = 0;
        g[to].push_back(last++);
    }

    bool dfs(int v, int T, int lim) {
        if (v == T) {
            return true;
        }

        used[v] = true;

        for (int idx: g[v]) {
            if (!used[to[idx]] && cap[idx] - flow[idx] >= lim && dfs(to[idx], T, lim)) {
                flow[idx] += lim;
                flow[idx ^ 1] -= lim;
                return true;
            }
        }

        return false;
    }

    int getMaxFlow(int S, int T) {
        int resFlow = 0;
        int curFlow = 1 << 30;

        while (curFlow > 0) {
            if (dfs(S, T, curFlow)) {
                resFlow += curFlow;
            } else {
                curFlow >>= 1;
            }

            memset(used, false, sizeof used);
        }

        return resFlow;
    }
};

MaxFlow maxFlow;
int n, m, x;
int a[MAXE], b[MAXE], c[MAXE];

int flow(double mid) {
    maxFlow.clear();

    for (int i = 0; i < m; i++) {
        double val = c[i] / mid;
        maxFlow.addEdge(a[i], b[i], val > x ? x : int(val));
    }

    return maxFlow.getMaxFlow(1, n);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &m, &x);

    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    }

    double l = 0, r = 1e12;
    double ans = 0;
    for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2;
        

        if (flow(mid) >= x) {
            ans = mid;
            l = mid;
        } else {
            r = mid;
        }
    }

    printf("%.10lf\n", ans * x);

    return 0;
}
