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
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

struct Node {
    int l, r, key, prior, size;
    ll sum;
} t[maxn];

inline void init(int it, int x) {
    t[it].l = 0;   
    t[it].r = 0;
    t[it].key = x; 
    t[it].prior = (rand() << 16) ^ rand();   
    t[it].size = 1;
    t[it].sum = x; 
}

inline void update(int v) {
    if (v) {
        t[v].sum = t[v].key + t[t[v].l].sum + t[t[v].r].sum;
        t[v].size = 1 + t[t[v].l].size + t[t[v].r].size; 
    }
}

void split(int v, int& l, int& r, int key) {
    if (!v) {
        l = r = 0;
        return;
    }

    if (t[v].key <= key) {
        split(t[v].r, t[v].r, r, key);
        l = v;
    } else {
        split(t[v].l, l, t[v].l, key);
        r = v;
    }  

    update(r);
    update(l);
}

int merge(int l, int r) {
    if (!l || !r)
        return l ? l : r;

    int ans;

    if (t[l].prior > t[r].prior) {
        t[l].r = merge(t[l].r, r);
        ans = l;
    } else {
        t[r].l = merge(l, t[r].l);
        ans = r;
    }

    update(l);
    update(r);

    return ans;
}

int erase(int& v, int val) {
    if (!v)
        return 0;

    if (t[v].key == val) {
        int res = v;
        v = merge(t[v].l, t[v].r);
        return res;
    }
    
    if (t[v].key < val)
        return erase(t[v].r, val);

    return erase(t[v].l, val);
}

void insert(int& v, int it) {
    if (!v) {
        v = it;
    } else if (t[it].prior > t[v].prior) {
        split(v, t[it].l, t[it].r, t[it].key);
        v = it;
    } else {
        if (t[v].key < t[it].key)
            insert(t[v].r, it);
        else
            insert(t[v].l, it);
    }
}

double solve(int v, ll val, int add = 0, ll sm = 0) {
    if (!v)
        return (INF + .0) * INF;

    ll sz = add + 1 + t[t[v].l].size;
    ll _sm = sm + t[t[v].l].sum + t[v].key;

    if (sz * t[v].key - _sm > val)
        return solve(t[v].l, val, add, sm);

    double ans = t[v].key + (val - (sz * t[v].key - _sm) + .0) / sz;

    ans = min(ans, solve(t[v].r, val, sz, _sm));

    return ans;
}

void show(int v) {
    if (!v)
        return;

    show(t[v].l);
    cout << v << ' ' << t[v].key << ' ' << t[v].sum << ' ' << t[v].size << endl;
    show(t[v].r);
}

int n, q, h[maxn], p, x, tp;
int root, last = 1;
ll v;           

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    srand(time(NULL));
    t[0].size = 0;

    scanf("%d%d", &n, &q);

    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
        init(last, h[i]);
        insert(root, last);
        last++;
    }

    while (q --> 0) {
        scanf("%d", &tp);

        if (tp == 1) {
            scanf("%d%d", &p, &x);
            int it = erase(root, h[--p]);
            init(it, x);
            insert(root, it);
            h[p] = x;
        } else {                        
            scanf("%I64d", &v);
            printf("%.12lf\n", solve(root, v));
        }
    }

    return 0;
}
