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

struct Edge {
    int x, y;
    int cost;

    int getOther(int v) const {
        if (v == x) {
            return y;
        }

        return x;
    }

    bool operator < (const Edge& e) const {
        pair <int, int> my_pair = make_pair(min(x, y), max(x, y));
        pair <int, int> other_pair = make_pair(min(e.x, e.y), max(e.x, e.y));

        return my_pair < other_pair;
    }
};

Edge e[MAXN];

struct Cycle {
    vector <int> nodes;
    vector <int> edges;
    vector <int> sum;
    map <int, int> pos;
    int total;

    void add(int node, int edge) {
        nodes.push_back(node);
        edges.push_back(edge);
        pos[node] = nodes.size() - 1;
    }

    void precalc() {
        sum.resize(nodes.size());
        total = e[edges[0]].cost;
        sum[0] = e[edges[0]].cost;

        for (size_t i = 1; i < edges.size(); i++) {
            sum[i] = sum[i - 1] + e[edges[i]].cost;
            total += e[edges[i]].cost; 
        }
    }

    int dist(int from, int to) {
        from = pos[from];
        to = pos[to];

        if (from > to) {
            swap(from, to);
        }

        int ans1 = sum[to - 1];
        if (from > 0) {
            ans1 -= sum[from - 1];
        }

        return min(ans1, total - ans1);
    }

    void clear() {
        nodes.clear();
        edges.clear();
        sum.clear();
        pos.clear();
    }
};

struct Compare {
    bool operator () (int a, int b) {
        return e[a] < e[b];
    }
};

vector <int> g[MAXN];
set <int> EDGES;
int n;
Cycle cycle;

void clear() {
    cycle.clear();
    EDGES.clear();
    for (int i = 0; i < n; i++) {
        g[i].clear();
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    while (scanf("%d", &n) == 1 && n != 0) {
        clear();

        bool foundCycle = false;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].cost);
            g[e[i].x].push_back(i);
            g[e[i].y].push_back(i);

            if (EDGES.count(i)) {
                cycle.add(e[i].x, *EDGES.find(edge));
                cycle.add(e[i].y, i);
                foundCycle = true;
            }

            EDGES.insert(i);
        }

        if (!foundCycle) {
            dfsGetCycle(0);
        }

        cycle.precalc();
    }
    
    return 0;
}
