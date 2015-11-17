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
const int LG = 18;

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
    }

    void precalc() {
        reverse(all(nodes));
        reverse(all(edges));
        for (size_t i = 0; i < nodes.size(); i++) {
            pos[nodes[i]] = i;
        }

        sum.resize(nodes.size());
        total = e[edges[0]].cost;
        sum[0] = e[edges[0]].cost;

        for (size_t i = 1; i < edges.size(); i++) {
            sum[i] = sum[i - 1] + e[edges[i]].cost;
            total += e[edges[i]].cost; 
        }
    }

    int dist(int from, int to) {
        if (from == to) {
            return 0;
        }

        from = pos[from];
        to = pos[to];

        if (from > to) {
            swap(from, to);
        }

        int ans = sum[to - 1];
        if (from > 0) {
            ans -= sum[from - 1];
        }

        return min(ans, total - ans);
    }

    bool contains(int node) {
        return pos.count(node);
    }

    void clear() {
        nodes.clear();
        edges.clear();
        sum.clear();
        pos.clear();
    }
};

struct Compare {
    bool operator () (int a, int b) const {
        return e[a] < e[b];
    }
};

vector <int> g[MAXN];
set <int, Compare> EDGES;
int n;
Cycle cycle;
int color[MAXN];
bool add;

int dfsGetCycle(int v, int par = -1) {
    color[v] = 1;

    for (int idx: g[v]) {
        int to = e[idx].getOther(v);

        if (color[to] == 1 && to != par) {
            cycle.add(v, idx);
            color[v] = 2;
            return to;
        }

        if (color[to] == 0) {
            int res = dfsGetCycle(to, v);
            if (res != -1) {
                cycle.add(v, idx);

                color[v] = 2;
                if (v == res) {
                    return -1;
                }

                return res;
            }
        }
    }
    
    color[v] = 2;

    return -1;
}

int root[MAXN];
int dist[MAXN];
int anc[LG][MAXN];
int tin[MAXN], tout[MAXN], timer;

void dfsDist(int v, int par, int r) {
    if (v == r) {
        dist[v] = 0;
    }

    root[v] = r;
    tin[v] = timer++;
    anc[0][v] = par;
    for (int i = 1; i < LG; i++) {
        anc[i][v] = anc[i - 1][anc[i - 1][v]];
    }

    for (int idx: g[v]) {
        int to = e[idx].getOther(v);
        if (!cycle.contains(to) && to != par) {
            dist[to] = dist[v] + e[idx].cost;
            dfsDist(to, v, r);
        }
    }

    tout[v] = timer++;
}

bool ancestor(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b) {
    if (ancestor(a, b)) {
        return a;
    }

    if (ancestor(b, a)) {
        return b;
    }

    for (int i = LG - 1; i >= 0; i--) {
        if (!ancestor(anc[i][b], a)) {
            b = anc[i][b];
        }
    }

    return anc[0][b];
}

void clear() {
    timer = 0;
    cycle.clear();
    EDGES.clear();
    for (int i = 0; i < n; i++) {
        g[i].clear();
    }

    memset(color, false, sizeof(int) * (n + 1));
}

int query(int a, int b) {
    if (cycle.contains(a) && cycle.contains(b)) {
        return cycle.dist(a, b);
    }

    if (cycle.contains(a)) {
        return dist[b] + cycle.dist(a, root[b]);
    }

    if (cycle.contains(b)) {
        return dist[a] + cycle.dist(root[a], b);
    }

    if (root[a] == root[b]) {
        int l = lca(a, b);
        return dist[a] + dist[b] - 2 * dist[l];
    }

    return dist[a] + dist[b] + cycle.dist(root[a], root[b]);
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
                cycle.add(e[i].x, *EDGES.find(i));
                cycle.add(e[i].y, i);
                foundCycle = true;
            }

            EDGES.insert(i);
        }

        if (!foundCycle) {
            dfsGetCycle(0);
        }

        cycle.precalc();

        for (int node: cycle.nodes) {
            dfsDist(node, node, node);
        }
        /*
        for (int node: cycle.nodes) {
            cout << node << ' ';
        }   
        cout << endl;

        for (int edge: cycle.edges) {
            cout << e[edge].cost << ' ';
        }
        cout << endl;
        */
        int q;
        scanf("%d", &q);

        while (q--) {
            int a, b;
            scanf("%d%d", &a, &b);
            printf("%d\n", query(a, b));
        }
    }
    
    return 0;
}
