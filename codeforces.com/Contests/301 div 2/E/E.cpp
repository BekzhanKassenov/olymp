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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Node;

typedef Node* pNode;

struct Node {
    pNode left, right;
    int sum;
    int flag;

    Node() :
        left(NULL),
        right(NULL),
        sum(0),
        flag(0) { }
};

pNode& getNode(pNode& v) {
    if (v == NULL) {
        v = new Node();
    }

    return v;
}

void push(pNode v, int l, int r) {
    v->sum += (r - l + 1) * v->flag;

    if (l != r && v->flag != 0) {
        getNode(v->left)->flag += v->flag;
        getNode(v->right)->flag += v->flag;
    }

    v->flag = 0;
}

void update(pNode v, int l, int r, int ql, int qr, int val) {
    push(v, l, r);

    if (ql > r || l > qr || ql > qr) {
        return;
    }

    if (ql <= l && r <= qr) {
        v->flag += val;
        push(v, l, r);
        return;
    }

    int mid = (l + r) / 2;
    update(getNode(v->left), l, mid, ql, qr, val);
    update(getNode(v->right), mid + 1, r, ql, qr, val);

    v->sum = getNode(v->left)->sum + getNode(v->right)->sum;
}

int sum(pNode v, int l, int r, int ql, int qr) {
    push(v, l, r);

    if (ql > r || l > qr) {
        return 0;
    }

    if (ql <= l && r <= qr) {
        return v->sum;
    }

    int mid = (l + r) / 2;
    return sum(getNode(v->left), l, mid, ql, qr) + 
           sum(getNode(v->right), mid + 1, r, ql, qr);
}

map <int, int> Map;
int n, a, b, N;
pNode root = new Node();

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);

        if (!Map.count(a)) {
            Map[a] = a;
        }

        if (!Map.count(b)) {
            Map[b] = b;
        }

        swap(Map[a], Map[b]);
        N = max(N, max(a, b));
    }

    long long ans = 0;
    for (auto it = Map.begin(); it != Map.end(); it++) {
        int num = it->second;
        
        ans += sum(root, 1, N, num, N);
        update(root, 1, N, num, num, 1);

        auto nxt = it;
        nxt++;
        
        if (nxt != Map.end()) {
            int l = it->first + 1;
            int r = nxt->first - 1;

            if (l <= r) {
                long long cnt = sum(root, 1, N, r, N);
                ans += cnt * (r - l + 1ll);

//                cerr << l << ' '  << r << ' ' << cnt << endl;
                update(root, 1, N, l, r, 1);
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}
