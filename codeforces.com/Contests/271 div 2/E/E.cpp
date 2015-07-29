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
const long long INF = (long long)(1e15 + 1);
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Node {
    Node *l, *r;
    long long left, right;
    pair <int, int> mx;

    Node() : l(NULL), r(NULL), left(0), right(0), mx() { }
};

void combine(pair <int, int>& a, const pair <int, int>& b) {
    if (a.first < b.first)
        a = b;
}

void update(Node *v, long long pos, int val, int tpos) {
    if (v -> left == pos && v -> right == pos) {
        combine(v -> mx, make_pair(val, tpos));
        return;
    }

    long long mid = (v -> left + v -> right) >> 1;

    if (pos <= mid) {
        if (v -> l == NULL)
            v -> l = new Node();

        v -> l -> left = v -> left;
        v -> l -> right = mid;

        update(v -> l, pos, val, tpos);
        combine(v -> mx, v -> l -> mx);
    } else {
        if (v -> r == NULL)
            v -> r = new Node();

        v -> r -> left = mid + 1;
        v -> r -> right = v -> right;

        update(v -> r, pos, val, tpos);
        combine(v -> mx, v -> r -> mx);
    }
}

pair <int, int> get(Node *v, long long l, long long r) {
    if (v == NULL || v -> left > r || l > v -> right)
        return pair <int, int> ();

    if (l <= v -> left && v -> right <= r)
        return v -> mx;

    pair <int, int> res = get(v -> l, l, r);
    combine(res, get(v -> r, l, r));
    
    return res;
}

int n, d;
Node *root;
long long a[MAXN];
int dp[MAXN], par[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    root = new Node();
    root -> left = 0;
    root -> right = INF;

    scanf("%d%d", &n, &d);

    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &a[i]);
    }

    int ans = 0;
    int ansp = 0;
    for (int i = 1; i <= n; i++) {
        long long left = max(0ll, a[i] - d);
        long long right = min(a[i] + d, INF);

        pair <int, int> res = get(root, 1, left);
        combine(res, get(root, right, INF));

        //cout << 0 << ' ' << left << "   " << right << ' ' << INF << endl;

        dp[i] = res.first + 1;
        par[i] = res.second;
        update(root, a[i], dp[i], i);

        //cout << i << ' ' << a[i] << ' ' << dp[i] << endl;

        if (dp[i] > ans) {
            ans = dp[i];
            ansp = i;
        }
    }


    printf("%d\n", ans);

    vector <int> res;
    while (ansp != 0) {
        res.push_back(ansp);
        ansp = par[ansp];
    }

    reverse(all(res));
    for (size_t i = 0; i < res.size(); i++)
        printf("%d ", res[i]);

    return 0;
}
