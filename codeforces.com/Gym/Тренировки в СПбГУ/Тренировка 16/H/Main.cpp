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
const int MAXN = 135 * 1000 * 2;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Node {
    int key, val;
    int prior;

    Node *left, *right;

    Node(int key = 0, int val = 0) :
        key(key),
        val(val),
        prior((rand() << 16) ^ rand()),
        left(NULL),
        right(NULL) { }
};

typedef Node* pNode;

void split(pNode v, pNode& l, pNode &r, int key) {
    if (v == NULL) {
        l = r = NULL;
        return;
    }

    if (key <= v->key) {
        split(v->left, l, v->left, key);
        r = v;
    } else {
        split(v->right, v->right, r, key);
        l = v;
    }
}

pNode merge(pNode l, pNode r) {
    if (l == NULL || r == NULL) {
        return (l == NULL) ? r : l;
    }

    pNode result = NULL;

    if (l->prior > r->prior) {
        l->right = merge(l->right, r);
        result = l;
    } else {
        r->left = merge(l, r->left);
        result = r;
    }

    return result;
}

pNode root = NULL;

void insert(int key, int val) {
    pNode node = new Node(key, val);

    pNode tree1, tree2;

    split(root, tree1, tree2, key);

    root = merge(tree1, merge(node, tree2));
}

int n, m, x;
int a[MAXN];
int last = 1;

void traverse(pNode v) {
    if (v == NULL) {
        return;
    }

    traverse(v->left);

    last = max(last, v->key);
    a[last++] = v->val;

    traverse(v->right);
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);

        insert(x, i);
    }

    traverse(root);

    printf("%d\n", last - 1);
    for (int i = 1; i < last; i++) {
        printf("%d%c", a[i], " \n"[i == last - 1]);
    }

    return 0;
}
