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
const long long MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
vector <int> comp[MAXN];
int color[MAXN];

struct Tree {
    long long t[MAXN];
    long long power[MAXN];
    long long a[MAXN];
    int BASE;

    Tree() {
        srand(time(NULL));
        BASE = max(239, rand());
        power[0] = 1;
        for (int i = 1; i < MAXN; i++) {
            power[i] = (power[i - 1] * BASE) % MOD;
        }
    }

    void update(int pos, long long nval) {
        long long to_erase = a[pos] * power[pos];
        to_erase = (-to_erase) % MOD;
        to_erase = (to_erase + MOD) % MOD;

        a[pos] = nval;
        long long to_add = (a[pos] * power[pos]) % MOD;
        long long to_update = (to_add + to_erase) % MOD;

        add(pos, to_update);
    }

    void add(int pos, long long val) {
        for (int i = pos; i <= n; i |= i + 1) {
            t[i] = (t[i] + val) % MOD;
        }
    }

    long long sum(int pos) {
        long long result = 0;
        for (int i = pos; i > 0; i = (i & (i + 1)) - 1) {
            result += t[i];
            result %= MOD;
        }

        return result % MOD;
    }

    long long sum(int l, int r) {
        long long result = sum(r) - sum(l - 1);
        result %= MOD;
        result += MOD;
        result %= MOD;

        return result;
    }

    bool equal(int x, int y, int len) {
        long long s1 = sum(x, x + len - 1);
        long long s2 = sum(y, y + len - 1);

        return (power[y + len - 1] * s1) % MOD == (power[x + len - 1] * s2) % MOD;
    }

    int getNext(int x, int y, int l) {
        if (equal(x, y, l)) {
            return -1;
        }

        if (a[x] != a[y]) {
            return 0;
        }

        int _left = 0, _right = l;

        int ans = l;
        while (_left <= _right) {
            int mid = (_left + _right) / 2;

            if (!equal(x, y, mid)) {
                ans = mid - 1;
                _right = mid - 1;
            } else {
                _left = mid + 1;
            }
        }

        return ans;
    }
};

Tree tree;

void init() {
    for (int i = 0; i <= n; i++) {
        tree.t[i] = 0;
        tree.a[i] = 0;
        comp[i].clear();
        comp[i].push_back(i);
        color[i] = i;
    }

    for (int i = 0; i <= n; i++) {
        tree.update(i, i);
    }
}

void query(int x, int y, int l) {
    int len;
    while ((len = tree.getNext(x, y, l)) != -1) {
        int c1 = color[x + len];
        int c2 = color[y + len];
        
        assert(c1 != c2);

        if (comp[c1].size() > comp[c2].size()) {
            swap(c1, c2);
        }

        for (int idx: comp[c1]) {
            tree.update(idx, c2);
            comp[c2].push_back(idx);
            color[idx] = c2;
        }

        comp[c1].clear();
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    while (scanf("%d%d", &n, &m) == 2) {
        init();
        for (int i = 0; i < m; i++) {
            int x, y, l;
            scanf("%d%d%d", &x, &y, &l);

            query(x, y, l);
        }

        int ans = 1;
        for (int i = 1; i <= n; i++) {
            if (!comp[i].empty()) {
                ans = (1ll * ans * 26) % MOD;
            }
        }

        printf("%d\n", ans);
    }
    
    return 0;
}
