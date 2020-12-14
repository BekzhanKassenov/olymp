/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const double INF = 1e50;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

std::mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
std::uniform_int_distribution<> dist(0, 2000000000);

int next_rnd() {
    return dist(mt);
}

struct Node {
    Node *l, *r;
    int key, prior, size, cnt;
    ll sum;
};

Node *NULL_NODE;

void init(Node* it, int x) {
    it->l = NULL_NODE;
    it->r = NULL_NODE;
    it->key = x;
    it->prior = next_rnd();   
    it->size = 1;
    it->cnt = 1;
    it->sum = x;
}

inline void update(Node* v) {
    if (v != NULL_NODE) {
        v->sum = v->key * v->cnt + v->l->sum + v->r->sum;
        v->size = v->cnt + v->l->size + v->r->size;
    }
}

void split(Node* v, Node*& l, Node*& r, int key) {
    if (v == NULL_NODE) {
        l = r = NULL_NODE;
        return;
    }

    if (v->key < key) {
        split(v->r, v->r, r, key);
        l = v;
    } else {
        split(v->l, l, v->l, key);
        r = v;
    }  

    update(r);
    update(l);
}

Node* merge(Node* l, Node* r) {
    if (l == NULL_NODE || r == NULL_NODE) 
        return (l != NULL_NODE) ? l : r;

    Node* ans;

    if (l->prior > r->prior) {
        l->r = merge(l->r, r);
        ans = l;
    } else {
        r->l = merge(l, r->l);
        ans = r;
    }

    update(l);
    update(r);

    return ans;
}

void erase(Node*& v, int val) {
    if (v == NULL_NODE)
        return;

    if (v->key == val) {
        if (v->cnt > 0) {
            v->cnt--;
        } else {
            v = merge(v->l, v->r);
        }
        update(v);
    }
    
    if (v->key < val)
        erase(v->r, val);
    else 
        erase(v->l, val);
    update(v);
}

void insert_real(Node*& v, Node* it) {
    if (v == NULL_NODE) {
        v = it;
    } else if (it->prior > v->prior) {
        split(v, it->l, it->r, it->key);
        v = it;
    } else {
        if (v->key <= it->key) {
            insert_real(v->r, it);
        } else {
            insert_real(v->l, it);
        }
    }
    update(v);
}

bool maybe_insert(Node* v, int val) {
    if (v == NULL_NODE) {
        return false;
    }
    bool res;
    if (v->key == val) {
        v->cnt++;
        res = true;
    } else {
        res = maybe_insert(v->key < val ? v->r : v->l, val);
    }
    update(v);
    return res;
}

double solve(Node* v, ll val, int add = 0, ll sm = 0) {
    if (v == NULL_NODE)
        return INF;

    ll sz = add + v->l->size;
    ll _sm = sm + v->l->sum;
    ll to_equalize = sz * v->key - _sm;

    if (to_equalize > val) {
        return solve(v->l, val, add, sm);
    }

    double ans = v->key + (val - to_equalize + .0) / (sz + v->cnt);

    ans = min(ans, solve(v->r, val, sz + v->cnt, _sm + v->cnt * v->key));

    return ans;
}

int n, q, h[maxn], p, x, tp;
Node* root;
ll v;           

void insert(int val) {
    if (maybe_insert(root, val)) {
        return;
    }
    Node* to_insert = new Node();
    init(to_insert, val);
    insert_real(root, to_insert);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    NULL_NODE = new Node({NULL, NULL, 0, 0, 0, 0});
    root = NULL_NODE;

    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> h[i];
        insert(h[i]);
    }

    while (q --> 0) {
        cin >> tp;

        if (tp == 1) {
            cin >> p >> x;
            p--;
            erase(root, h[p]);
            h[p] = x;

            insert(h[p]);
        } else {
            cin >> v;              
            cout << fixed << setprecision(8) << solve(root, v) << endl;
        }
    }

    return 0;
}
