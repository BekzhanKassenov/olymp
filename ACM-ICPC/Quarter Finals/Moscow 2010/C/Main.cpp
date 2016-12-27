/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "coding"

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

int get_rand() {
    static bool init = false;
    if (!init) {
        srand(time(NULL));
        init = true;
    }

    return (rand() << 16) ^ rand();
}

struct Node;

typedef Node* pNode;

struct Node {
    pNode left, right;
    char val;
    int prior, size;

    Node() : Node('\0') { }

    Node(char c) :
        left(NULL), right(NULL), val(c), prior(get_rand()), size(1) { }

};

int get_size(pNode v) {
    return v == NULL ? 0 : v->size;
}

void update(pNode v) {
    if (v != NULL) {
        v->size = get_size(v->left) + get_size(v->right) + 1;
    }   
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

    update(ans);
    return ans;
}

void split(pNode v, pNode& l, pNode& r, int key, int add = 0) {
    if (v == NULL) {
        l = r = NULL;
        return;
    }

    int vkey = add + get_size(v->left) + 1;
    if (vkey <= key) {
        split(v->right, v->right, r, key, vkey);
        l = v;
    } else {
        split(v->left, l, v->left, key, add);
        r = v;
    }

    update(l);
    update(r);
}

pNode shift(pNode root, int l, int r, int k) {
    int len = r - l + 1;
    pNode tree1, tree2, tree3, tree4;

    split(root, tree1, tree3, l + len - k);
    split(tree1, tree1, tree2, l);
    split(tree3, tree3, tree4, k);

    return merge(merge(tree1, tree3), merge(tree2, tree4));
}

pNode root = NULL;

void query(int l, int r, int k) {
    l--, r--;
    int len = r - l + 1;
    k %= len;
    k = len - k;
    k %= len;

    if (k != 0) {
        root = shift(root, l, r, k);
    }
}

void print(pNode v) {
    if (v != NULL) {
        print(v->left);
        putchar(v->val);
        print(v->right);
    }
}

pNode build(char s[], int len) {
    pNode result = NULL;
    for (int i = 0; i < len; i++) {
        result = merge(result, new Node(s[i]));
    }

    return result;
}

char s[MAXN];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    gets(s);
    root = build(s, strlen(s));

    int n;
    scanf("%d", &n);

    vector <tuple <int, int, int> > queries;

    for (int i = 0; i < n; i++) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        queries.emplace_back(l, r, k);
    }

    for (int i = n - 1; i >= 0; i--) {
        int l, r, k;
        tie(l, r, k) = queries[i];

        query(l, r, k);
    }

    print(root);

    return 0;
}
