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
const int MOD = 99990001;   
const int INF = 2000 * 1000 * 1000;
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

/*================ Treap =====================*/
struct Node {
    Node *parent;
    Node *left, *right;

    int size, prior;
    int idx, minidx;

    long long addFlag;
    long long mulFlag;
    long long value;

    int offset;

    Node(int idx = -1, long long value = 0) : 
        parent(NULL),
        left(NULL),
        right(NULL),
        size(1),
        prior((rand() << 16) ^ rand()),
        idx(idx), 
        minidx(idx),
        addFlag(0),
        mulFlag(1),
        value(value),
        offset(0) { }

    void applyMul(long long mul) {
        addFlag *= mul;
        addFlag %= MOD;

        mulFlag *= mul;
        mulFlag %= MOD;
    }

    void applyAdd(long long add) {
        addFlag += add;
        addFlag %= MOD;
    }

    void push() {
        if (left != NULL) {
            applyMul(left, mulFlag);
            applyAdd(left, addFlag);
        }

        if (right != NULL) {
            applyMul(right, mulFlag);
            applyAdd(right, addFlag);
        }

        value *= mulFlag;
        value += addFlag;
        value %= MOD;
        
        addFlag = 0;
        mulFlag = 1;
    }
};

typedef Node* pNode;

int getSize(pNode v) {
    if (v != NULL) {
        return v->size;
    }

    return 0;
}   

int getMinidx(pNode v) {
    if (v != NULL) {
        return v->minidx;
    }

    return INF;
}

long long getValue(pNode v, int key, int add = 0) {
    assert(v != NULL);

    push(v);

    int curKey = v->offset + add + getSize(v->left);

    printf("GetValue: v=%d curKey=%d key=%d\n", v->idx, curKey, key);

    if (curKey == key) {
        return v->value;
    }

    if (key < curKey) {
        return getValue(v->left, key, add);
    }
    
    return getValue(v->right, key, add + getSize(v->left));
}

void update(pNode v) {
    if (v != NULL) {
        v->size = getSize(v->left) + getSize(v->right) + 1;
        v->minidx = min(min(getMinidx(v->left), getMinidx(v->right)), v->idx);

        if (v->left) {
            v->left->parent = v;
            v->left->offset = v->offset;
        }

        if (v->right) {
            v->right->parent = v;
            v->left->offset = v->offset;
        }
    }
}

pNode getRoot(pNode v) {
    if (v->parent == NULL) {
        return v;
    }

    return getRoot(v->parent);
}

void split(pNode v, pNode& l, pNode& r, int key, int add = 0) {
    if (v == NULL) {
        l = r = NULL;
        return;
    }

    push(v);

    int curKey = v->offset + add + getSize(v->left);

    if (curKey < key) {
        split(v->right, v->right, r, key, add + getSize(v->left));
        l = v;
    } else {
        split(v->left, l, v->left, key, add);
        r = v;
    }

    update(l);
    update(r);
}

pNode merge(pNode l, pNode r) {
    push(l);
    push(r);

    if (l == NULL || r == NULL) {
        return l ? l : r;
    }
    
    pNode result = NULL;

    if (l->prior > r->prior) {
        l->right = merge(l->right, r);
        result = l;
    } else {
        r->left = merge(l, r->left);
        result = r;
    }

    update(l);
    update(r);
    return result;
}

/*================ End of Treap =====================*/

struct Edge {
    int from, to;
    int val;
    int lower;

    int other(int v) {
        assert(v == from || v == to);

        if (v == from) {
            return to;
        }

        return from;
    }
};

Edge e[MAXN];

int n, x;
vector <int> g[MAXN];
int tin[MAXN], tout[MAXN], timer = -1;
pNode node[MAXN], root = NULL;

void dfs(int v, int par = -1) {
    tin[v] = ++timer;

    int val = par == -1 ? 0 : e[par].val;
    node[v] = new Node(v, val);
    root = merge(root, node[v]);

    //printf("Number: %d, address: %p\n", v, node[v]);

    for (int idx: g[v]) {
        if (idx != par) {
            int to = e[idx].other(v);
            e[idx].lower = to;
            dfs(to, v);
        }
    }

    tout[v] = timer;
}

long long removeEdge(int idx) {
    int v = e[idx].lower;

    pNode root = getRoot(node[v]);
    pNode _left, _mid, _right;

    split(root, root, _right, tout[v] + 1);
    split(root, _left, _mid, tin[v]);

    root = merge(_left, _right);
    
    if (_mid) {
        _mid->parent = NULL;
        _mid->offset = root->offset + getSize(root);
        printf("MID: %d\n", _mid->idx);
    }

    
    long long res = getValue(_mid, tin[v]);

    if (getSize(root) < getSize(_mid) || (getSize(root) == getSize(_mid) && getMinidx(root) < getMinidx(_mid))) {
        applyMul(root, res);
        applyAdd(_mid, res);
    } else {
        applyAdd(root, res);
        applyMul(_mid, res);
    }

    printf("Result: %I64d\n", res);
    
    return res;
}

void print() {
    for (int i = 1; i <= n; i++) {
        
        printf("Node: %d, value: %I64d", i, node[i]->value);
        
        if (node[i]->parent != NULL) {
            printf(", parent: %d", node[i]->parent->idx);
        }

        if (node[i]->left != NULL) {
            printf(", left: %d", node[i]->left->idx);
        }

        if (node[i]->right != NULL) {
            printf(", right: %d", node[i]->right->idx);
        }

        puts("");
        fflush(stdout);
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i < n; i++) {
        scanf("%d%d%d", &e[i].from, &e[i].to, &e[i].val);
        g[e[i].from].push_back(i);
        g[e[i].to].push_back(i);
    }

    dfs(1);

    print();

    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &x);
        printf("%I64d\n", removeEdge(x));
        fflush(stdout);

        print();
    }

    return 0;
}
