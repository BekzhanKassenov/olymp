#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

class CartesianTree {
public:
    CartesianTree() : root(NULL), size(0) { }

    ~CartesianTree() {
        destroy(root);
    }

    inline void init(int size) {
        CartesianTree :: size = size;
        for (int i = 0; i < size; i++) {
            pNode temp_node = new Node();
            root = merge(root, temp_node);
        }
    }

    void increase(int pos, int val) {
        pNode t1, t2, t3;
        split(root, t1, t2, pos);
        split(t2, t2, t3, 1);

        t2 -> val += val;
        
        root = merge(merge(t1, t2), t3);
    }

    int get(int l, int r) {
        pNode t1, t2, t3;
        split(root, t1, t2, l);
        split(t2, t2, t3, r - l + 1);

        int res = node_max(t2);

        root = merge(merge(t1, t2), t3);

        return res;
    }

private:
    struct Node {
        int val, prior;
        Node *l, *r;
        int sz, mx;

        Node() : val(0), prior((rand() << 16) + rand()), l(NULL), r(NULL), sz(1), mx(0) { }
    };            

    typedef Node* pNode;

    inline int node_size(pNode v) {
        return (v ? v -> sz : 0);
    }

    inline int node_max(pNode v) {
        return (v ? v -> mx : 0);
    }

    inline void update(pNode v) {
        if (v == NULL)
            return;

        v -> mx = max(node_max(v -> l), node_max(v -> r));
        v -> mx = max(v -> val, v -> mx);
        v -> sz = node_size(v -> l) + node_size(v -> r) + 1;
    }

    void split(pNode v, pNode& l, pNode& r, int key, int add = 0) {
        if (v == NULL) {
            l = r = NULL;
            return;
        }

        int pos = add + node_size(v -> l);

        if (pos < key) {
            split(v -> r, v -> r, r, key, pos + 1);
            l = v;
        } else {
            split(v -> l, l, v -> l, key, add);
            r = v;
        }

        update(v);
    }

    pNode merge(pNode l, pNode r) {
        if (l == NULL || r == NULL) {
            update(l ? l : r);
            return (l ? l : r);
        }

        pNode ans;
        
        if (l -> prior > r -> prior) {
            l -> r = merge(l -> r, r);
            ans = l;
        } else {
            r -> l = merge(l, r -> l);
            ans = r;
        }
        
        update(ans);
        
        return ans;
    }

    void destroy(pNode v) {
        if (v == NULL)
            return;

        destroy(v -> l);
        destroy(v -> r);

        delete v;
    }

    pNode root;
    int size;
};

const int maxn = 100010;

CartesianTree tree[maxn];
vector <int> g[maxn];
int tin[maxn], tout[maxn], par[maxn], size[maxn];
int chain[maxn], chain_pos[maxn], chain_size[maxn], root[maxn];
int n, m, x, y, timer, chains_cnt;
char c;

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

inline int create_root(int v) {
    root[chains_cnt] = v;
    return chains_cnt++;
}

inline bool heavy(int v, int to) {
    return 2 * size[to] >= size[v];
}

inline bool ancestor(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

void build(int v, int v_chain) {
    chain[v] = v_chain;
    chain_pos[v] = chain_size[v_chain]++;

    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to != par[v])
            build(to, heavy(v, to) ? v_chain : create_root(to));
    }
}

inline int get_query(int a, int b) {
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
#endif // ONLINE_JUDGE

    srand(time(NULL));

    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &x, &y);
        g[--x].push_back(--y);
        g[y].push_back(x);
    }

    dfs(0);

    build(0, create_root(0));

    for (int i = 0; i < chains_cnt; i++)
        tree[i].init(chain_size[i]);

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("\n%c %d %d", &c, &x, &y);

        if (c == 'I') {
            x--;
            tree[chain[x]].increase(chain_pos[x], y);
        } else {
            printf("%d\n", get_query(--x, --y));
        }
    }

    return 0;
}
