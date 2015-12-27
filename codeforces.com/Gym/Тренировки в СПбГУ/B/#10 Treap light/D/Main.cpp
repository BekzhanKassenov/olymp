/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "key"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 280000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Node;

typedef Node* pNode;

struct Node {
    int num, prior;
    int pos, size;
    int flag;

    pNode left, right;

    Node(int pos, int num) :
        num(num),
        prior((rand() << 16) ^ rand()),
        pos(pos),
        size(1),
        flag(0),
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

void splitByKey(pNode v, pNode& l, pNode& r, int key) {
    if (v == NULL) {
        l = r = NULL;
        return;
    }

    push(v);

    if (v->pos <= key) {
        splitByKey(v->right, v->right, r, key);
        l = v;
    } else {
        splitByKey(v->left, l, v->left, key);
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
    if (l->prior < r->prior) {
        l->right = merge(l->right, r);
        ans = l;
    } else {
        r->left = merge(l, r->left);
        ans = r;
    }

    update(ans);

    return ans;
}

void getFirstSegment(pNode v, pNode& l, pNode& r, int start, int add = 0) {
    push(v);

    if (v == NULL) {
        l = r = NULL;
        return;
    }

    int key = add + getSize(v->left);
    if (v->pos - start == key) {
        getFirstSegment(v->right, v->right, r, start, key + 1);
        l = v;
    } else {
        getFirstSegment(v->left, l, v->left, start, add);
        r = v;
    }

    update(l);
    update(r);
}

pNode getMin(pNode v) {
    if (v == NULL) {
        return NULL;
    }

    push(v);

    if (v->left == NULL) {
        return v;
    }

    return getMin(v->left);
}

pNode root = NULL;

void insert(int to, int x) {
    pNode root1, root2;

    splitByKey(root, root1, root2, to - 1);
    pNode minNode = getMin(root2);

    if (minNode != NULL && minNode->pos == to) {
        pNode temp1, temp2;
        getFirstSegment(root2, temp1, temp2, minNode->pos);

        if (temp1 != NULL) {
            temp1->flag++;
        }

        root2 = merge(temp1, temp2);
    }

    pNode item = new Node(to, x);

    root = merge(merge(root1, item), root2);
}

int ans[MAXN];
int N;

void traverse(pNode v) {
    push(v);

    if (v != NULL) {
        ans[v->pos] = v->num;
        N = max(N, v->pos);
        traverse(v->left);

        traverse(v->right);
    }
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        insert(x, i);
    }

    traverse(root);

    printf("%d\n", N);
    for (int i = 1; i <= N; i++) {
        printf("%d ", ans[i]);
    }

    puts("");

    return 0;
}
