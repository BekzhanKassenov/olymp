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
const int MAXN = 400010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Node {
    int val;
    Node *left, *right;

    Node(int val = 0, Node* left = NULL, Node* right = NULL) :
        val(val),
        left(left),
        right(right) { }
};

struct Node;

typedef Node* pNode;

pNode getNode(pNode& v) {
    if (v == NULL) {
        v = new Node();
    }

    return v;
}

pNode update(pNode v, int l, int r, int pos, int val) {
    if (l == r) {
        return new Node(val);
    }

    int mid = (l + r) / 2;
    
    pNode result = NULL;
    if (pos <= mid) {
        result = new Node(0, update(getNode(v->left), l, mid, pos, val), v->right);
    } else {
        result = new Node(0, v->left, update(getNode(v->right), mid + 1, r, pos, val));
    }

    result->val = max(getNode(result->left)->val, getNode(result->right)->val);
    return result;
}

int getMax(pNode v, int l, int r, int ql, int qr) {
    if (ql > qr || ql > r || l > qr || v == NULL) {
        return 0;
    }

    if (ql <= l && r <= qr) {
        return v->val;
    }

    int mid = (l + r) / 2;

    return max(getMax(v->left, l, mid, ql, qr), getMax(v->right, mid + 1, r, ql, qr));
}

int n, m;
int h[MAXN];
pNode root_l[MAXN], root_r[MAXN];
vector <int> mapping;
map <int, int> Map;

void compress() {
    mapping = vector <int>(h + 1, h + n + 1);
    sort(all(mapping));
    mapping.resize(unique(all(mapping)) - mapping.begin());

    for (int i = 1; i <= n; i++) {
        int val = lower_bound(all(mapping), h[i]) - mapping.begin();
        Map[h[i]] = val;    
        h[i] = val;
    }
}

int getNext(int num) {
    auto ptr = Map.upper_bound(num);
    if (ptr == Map.end()) {
        return n;
    }

    return ptr->second;
}

int getPrev(int num) {
    auto ptr = Map.lower_bound(num);
    if (ptr == Map.begin()) {
        return -1;
    }

    ptr--;
    return ptr->second;
}

int d[MAXN];
long long cnt[MAXN];

void calc() {
d[0] = -INF;
cnt[0] = 1;
for (int i=1; i<=n; ++i)
	d[i] = INF;
 
for (int i=0; i<n; i++) {
	int j = int (upper_bound (d, d + n + 1, h[i]) - d);
	if (d[j-1] < h[i] && h[i] < d[j]) {
		d[j] = h[i];
        cnt[j] += cnt[i];
    }
}

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
   
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
    }

    compress();

    int ans = 0;
    root_l[0] = NULL;
    for (int i = 1; i <= n; i++) {
        int p = getMax(root_l[i - 1], 0, n - 1, 0, h[i] - 1);

        root_l[i] = update(getNode(root_l[i - 1]), 0, n - 1, h[i], p + 1);
        ans = max(ans, p + 1);
    }

    int q = 0;
    root_r[n + 1] = NULL;
    for (int i = n; i >= 1; i--) {
        int p = getMax(root_r[i + 1], 0, n - 1, h[i] + 1, n - 1);

        root_r[i] = update(getNode(root_r[i + 1]), 0, n - 1, h[i], p + 1);

        q = max(q, p + 1);
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);

        //cerr << b << ' ' << getPrev(b) << ' ' << getNext(b) << endl;

        int pl = getMax(root_l[a - 1], 0, n - 1, 0, getPrev(b));
        int pr = getMax(root_r[a + 1], 0, n - 1, getNext(b), n - 1);

        //cerr << a << ' ' << b << ' ' << pl << ' ' << pr << endl;

        int res = pl + pr + 1;

        if (cnt[a] != 1) {
            res = max(res, ans);
        }


        printf("%d\n", res);
    }

    return 0;
}
