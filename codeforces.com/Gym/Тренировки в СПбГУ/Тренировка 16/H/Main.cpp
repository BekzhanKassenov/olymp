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

struct Node;

typedef Node* pNode;

struct Node {
    int pos, val;
    int flag;
    int size, prior;

    pNode left, right;

    Node(int pos, int val) :
        pos(pos),
        val(val),
        flag(0),
        size(1),
        prior((rand() << 16) ^ rand()),
        left(NULL),
        right(NULL) { } 
};

int getSize(pNode v) {
    return v == NULL ? 0 : v->size;
}

void push(pNode v) {
    if (v != NULL && v->flag != 0) {
        v->pos += v->flag;

        if (v->left != NULL) {
            v->left->flag += v->flag;
        }

        if (v->right != NULL) {
            v->right->flag += v->flag;
        }

        v->flag = 0;
    }
}

void update(pNode v) {
    if (v != NULL) {
        v->size = getSize(v->left) + getSize(v->right) + 1;
    }
}

void split(pNode v, pNode& l, pNode& r, int key) {
    push(v);

    if (v == NULL) {
        l = r = NULL;
        return;
    }

    if (v->pos < key) {
        split(v->right, v->right, r, key);
        l = v;
    } else {
        split(v->left, l, v->left, key);
        r = v;
    }

    update(l);
    update(r);
}

pNode merge(pNode l, pNode r) {
    push(l);
    push(r);

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

pNode getMin(pNode v) {
    if (v == NULL) {
        return NULL;
    }

    if (v->left != NULL) {
        return getMin(v->left);
    }

    return v;
}

pNode getFirst(pNode v, int start, int add = 0) {
    push(v);

    if (v == NULL) {
        return NULL;
    }

    int pos = getSize(v->left) + add;

    if (v->pos - start != pos) {
        pNode temp = getFirst(v->left, start, add);

        return temp == NULL? v : temp;
    }

    return getFirst(v->right, start, pos + 1);
}

pNode root = NULL;
int n, m, x;

void insert(int to, int val) {
    pNode tree1, tree2;
    split(root, tree1, tree2, to);

    pNode mn = getMin(tree2);

    if (mn != NULL && mn->pos == to) {
        pNode temp = getFirst(tree2, to);

        if (temp != NULL) {
            pNode temp1, temp2;
            split(tree2, temp1, temp2, temp->pos);

            if (temp1 != NULL) {
                temp1->flag = 1;
            }

            tree2 = merge(temp1, temp2);
        } else {
            if (tree2 != NULL) {
                tree2->flag = 1;
            }
        }
    }

    pNode nitem = new Node(to, val);
    root = merge(merge(tree1, nitem), tree2);
}

int ans[MAXN];
int maxpos;

void traverse(pNode v) {
    if (v == NULL) {
        return;
    }

    push(v);

    traverse(v->left);
    
    maxpos = max(maxpos, v->pos);
    ans[v->pos] = v->val;
    
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

    printf("%d\n", maxpos);
    for (int i = 1; i <= maxpos; i++) {
        printf("%d%c", ans[i], " \n"[i == maxpos]);
    }

    return 0;
}
