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

struct Node;

typedef Node* pNode;

struct Node {
    int size;
    int prior;

    pNode left, right;
    pNode parent;

    Node() : 
        size(1),
        prior((rand() << 16) ^ rand()),
        left(NULL),
        right(NULL),
        parent(NULL) { }
};

int getSize(pNode v) {
    return v == NULL ? 0 : v->size;
}

void update(pNode v) {
    if (v != NULL) {
        v->size = getSize(v->left) + getSize(v->right) + 1;

        if (v->left != NULL) {
            v->left->parent = v;
        }

        if (v->right != NULL) {
            v->right->parent = v;
        }
    }
}

int getPos(pNode v) {
    if (v == NULL) {
        return 0;
    }

    vector <pNode> vec;
    while (v != NULL) {
        vec.push_back(v);
        v = v->parent;
    }

    reverse(all(vec));

    int result = getSize(vec.back()->left);
    for (size_t i = 0; i + 1 < vec.size(); i++) {
        if (vec[i]->right == vec[i + 1]) {
            result += getSize(vec[i]->left) + 1;
        }
    }

    return result;
}

void split(pNode v, pNode& l, pNode& r, int key, int add = 0) {
    if (v == NULL) {
        l = r = NULL;
        return;
    }

    int pos = add + getSize(v->left);

    if (pos <= key) {
        split(v->right, v->right, r, key, pos + 1);
        l = v;
    } else {
        split(v->left, l, v->left, key, add);
        r = v;
    }

    update(l);
    update(r);
}

pNode merge(pNode l, pNode r) {
    if (l == NULL || r == NULL) {
        return l == NULL ? r : l;
    }

    pNode ans = NULL;
    if (l->prior > r->prior) {
        l->right = merge(l->right, r);
        ans = l;
    } else {
        r->left = merge(l, r->left);
        ans = r;
    }

    update(l);
    update(r);
    update(ans);

    return ans;
}

pNode root = NULL;

int n;
char type;
int last;

Node node[MAXN];

void add(char type) {
    if (type == 'F') {
        root = merge(&node[last], root);
    } else {
        root = merge(root, &node[last]);
    }

    if (root != NULL) {
        root->parent = NULL;
    }

    last++;
}

int query(int x) {
    int pos = getPos(&node[x]);

    pNode tree1, tree2, tree3;
    split(root, tree2, tree3, pos);
    split(tree2, tree1, tree2, pos - 1);

    int size1 = getSize(tree1);
    int size2 = getSize(tree3);

    root = merge(tree3, tree1);

    if (root != NULL) {
        root->parent = NULL;
    }

    return min(size1, size2);
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("\n%c", &type);

        if (type == 'O') {
            int x;
            scanf("%d", &x);
            printf("%d\n", query(x - 1));    
        } else {
            add(type);
        }   
    }
    
    return 0;
}
