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

template <class T>
struct Node {
    Node <T> *left, *right;
    T data;

    Node(Node <T> *left, Node <T> *right, T data) :
        left(left), 
        right(right), 
        data(data) { }
};

template <class T>
Node <T>* build(int l, int r, const vector <T>& arr) {
    if (l == r) {
        return new Node <T> (NULL, NULL, arr[l]);
    }

    int mid = (l + r) / 2;
    return new Node <T> (build(l, mid, arr), build(mid + 1, r, arr), 0);
}

template <class T>
Node <T>* update(Node <T>* v, int l, int r, int pos, T val) {
    if (l == r) {
        return new Node <T> (NULL, NULL, val);
    }

    int mid = (l + r) / 2;
    if (pos <= mid) {
        return new Node <T> (update(v->left, l, mid, pos, val), v->right, v->data);
    }

    return new Node <T> (v->left, update(v->right, mid + 1, r, pos, val), v->data);
}

template <class T>
T get(Node <T>* v, int l, int r, int pos) {
    if (l == r) {
        return v->data;
    }

    int mid = (l + r) / 2;
    if (pos <= mid) {
        return get(v->left, l, mid, pos); 
    }

    return get(v->right, mid + 1, r, pos);
}

typedef Node <Node <int>* >* rootPtr;

int n, m;
rootPtr root[MAXN];
vector <vector <int> > arr;
vector <Node <int>* > vec;

int getValue(rootPtr root, int i, int j) {
    Node <int>* ptr = get(root, 1, n, i);
    return get(ptr, 1, n, j);
}

rootPtr setValue(rootPtr root, int i, int j, int val) {
    Node <int>* ptr = get(root, 1, n, i);
    ptr = update(ptr, 1, n, j, val);
    return update(root, 1, n, i, ptr);
}

rootPtr fupdate(rootPtr root, int x, int y, int val) {
    int old = getValue(root, x, y);
    val ^= old;

    for (int i = x; i <= n; i |= i + 1) {
        for (int j = y; j <= n; j |= j + 1) {
            int old = getValue(root, i, j);
            root = setValue(root, i, j, old ^ val);
        }
    }

    return root;
}

int query(rootPtr root, int x, int y) {
    int res = 0;
    for (int i = x; i > 0; i = (i & (i + 1)) - 1) {
        for (int j = y; j > 0; j = (j & (j + 1)) - 1) {
            res ^= getValue(root ,i, j);
        }
    }

    return res;
}

int query(rootPtr root, int x, int y, int xx, int yy) {
    return query(root, xx, yy) ^ 
           query(root, xx, y - 1) ^ 
           query(root, x - 1, yy) ^ 
           query(root, x - 1, y - 1);
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &n);

    arr.resize(n + 1, vector <int>(n + 1));
    vec.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
        }

        vec[i] = build(1, n, arr[i]);
    }

    root[1] = build(1, n, vec);
    int last = 1;

    scanf("%d", &m);

    for (int i = 1; i <= m; i++) {
        char type;
        scanf("\n%c", &type);

        if (type == 'i') {
            int q;
            scanf("%d", &q);

            last++;
            root[last] = root[last - 1];
            for (int i = 0; i < q; i++) {
                int x, y, val;
                scanf("%d%d%d", &x, &y, &val);
                root[last] = fupdate(root[last], x, y, val);
            }

        } else if (type == 'f') {
            int q;
            scanf("%d", &q);
            last++;
            root[last] = root[q];

        } else if (type == 'c') {
            int x, y, xx, yy;
            scanf("%d%d%d%d", &x, &y, &xx, &yy);

            printf("%d\n", query(root[last], x, y, xx, yy));
        }
    }

    return 0;
}
