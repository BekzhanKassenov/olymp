#include <cstdio>   
#include <vector>
#include <cassert>
#include <cstring>

using namespace std;

class SegmentTree {
public:
    SegmentTree() : t(NULL), size(0) { }

    ~SegmentTree() {
        if (t != NULL)
            delete[] t;
    }

    void init(int size) {
        SegmentTree :: size = size;

        t = new int[4 * size];
        memset(t, 0, 4 * size * sizeof(int));
    }

    void update(int pos, int val) {
        assert(pos >= 0 && pos < size);
        update(1, 0, size - 1, pos, val);
    }

    int get(int l, int r) {
        assert(l >= 0 && l < size && r >= 0 && r < size && l <= r);
        return get(1, 0, size - 1, l, r);
    }

private:
    void update(int v, int l, int r, int pos, int val) {
        if (l > r || pos < l || pos > r)
            return;

        if (l == r) {
            t[v] += val;
            return;
        }

        int mid = (l + r) >> 1;

        update(v << 1, l, mid, pos, val);
        update((v << 1) + 1, mid + 1, r, pos, val);
        t[v] = max(t[v << 1], t[(v << 1) + 1]);
    }

    int get(int v, int l, int r, int q_l, int q_r) {
        if (l > r || q_l > r || q_r < l)
            return 0;

        if (l >= q_l && r <= q_r)
            return t[v];

        int mid = (l + r) >> 1;

        return max(get(v << 1, l, mid, q_l, q_r), get((v << 1) + 1, mid + 1, r, q_l, q_r)); 
    }

    int *t, size;
};

const int maxn = 100010;

vector <int> g[maxn];
SegmentTree tree[maxn];
char c;
int n, m, x, y, timer, chains_cnt;
int tin[maxn], tout[maxn], size[maxn], par[maxn];
int chain[maxn], root[maxn], chain_pos[maxn], chain_size[maxn];

void dfs(int v, int pr = -1) {
    tin[v] = timer++;
    size[v] = 1;
    par[v] = pr;

    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to != pr) {
            dfs(to, v);
            size[v] += size[to];
        }
    }

    tout[v] = timer++;
}

bool heavy(int v, int to) {
    return (2 * size[to] >= size[v]); 
}

bool ancestor(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int new_root(int v) {
    root[chains_cnt] = v;
    return chains_cnt++;
}

void build(int v, int v_chain) {
    chain[v] = v_chain;
    chain_pos[v] = chain_size[v_chain]++;

    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to != par[v])
            build(to, heavy(v, to) ? v_chain : new_root(to));
    }
}

int get_query(int a, int b) {
    int res = 0, v;

    for (int i = 0; i < 2; i++) {
        while (!ancestor(v = root[chain[a]], b)) {
            res = max(res, tree[chain[a]].get(0, chain_pos[a]));
            a = par[v];
        }
        swap(a, b);
    }

    res = max(res, tree[chain[a]].get(min(chain_pos[a], chain_pos[b]), max(chain_pos[a], chain_pos[b])));

    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &x, &y);

        g[--x].push_back(--y);
        g[y].push_back(x);
    }
    dfs(0);
    build(0, new_root(0));

    for (int i = 0; i < chains_cnt; i++) {
        tree[i].init(chain_size[i]);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("\n%c %d %d", &c, &x, &y);

        if (c == 'I') {
            x--;
            tree[chain[x]].update(chain_pos[x], y);
        } else {
            printf("%d\n", get_query(--x, --y));
        }
    }

    return 0;
}
