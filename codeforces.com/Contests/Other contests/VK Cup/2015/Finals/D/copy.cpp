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
const int MAXN = 200010;
const int BSIZE = 512;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int parent[MAXN];
int size[MAXN];
int n;

int get_parent(int v) {
    if (parent[v] == v) {
        return v;
    }

    return v = get_parent(parent[v]);
}

void unite(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a != b) {
        if (size[b] > size[a]) {
            parent[b] = a;
            size[a] += size[b];
        } else {
            parent[a] = b;
            size[b] += size[a];
        }
    }
}

struct Block {
    int flag;
    int l, r;

    void init(int l, int r) {
        flag = -1;
        this->l = l;
        this->r = r;
    }

    void apply_flag() {
        if (flag != -1) {
            int par = get_parent(flag);
            for (int i = l; i <= r; i++) {
                unite(par, i);
            }

            flag = -1;
        }
    }

    void set_parent(int l, int r, int par) {
        apply_flag();
        par = get_parent(par);
        for (int i = l; i <= r; i++) {
            unite(par, i);
        }
    }

    void set_parent(int par) {
        if (flag == -1) {
            flag = par;
        } else {
            unite(par, flag);
            flag = par;
        }
    }
};

Block block[BSIZE];

void query1(int x, int y) {
    int block_x = x >> 9;
    int block_y = y >> 9;

    block[block_x].apply_flag();
    block[block_y].apply_flag();

    unite(x, y);
}

void query2(int l, int r) {
    int block_l = l >> 9;
    int block_r = r >> 9;

    if (block_l == block_r) {
        block[block_l].set_parent(l, r, l);
        return;
    }

    int par = get_parent(l);

    int start = block_l;
    int end = block_r;

    if (l % BSIZE != 0) {
        block[block_l].set_parent(l, block[block_l].r, par);
        start = block_l + 1;
    }

    if (r % BSIZE != BSIZE - 1) {
        block[block_r].set_parent(block[block_r].l, r, par);
        end = block_r - 1;
    }

    for (int i = start; i < end; i++) {
        block[block_r].set_parent(par);
    }
}

bool query3(int x, int y) {
    int block_x = x >> 9;
    int block_y = y >> 9;

    block[block_x].apply_flag();
    block[block_y].apply_flag();

    x = get_parent(x);
    y = get_parent(y);

    return x == y;
}

int q, type, x, y;
stringstream ss;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &q);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        size[i] = 1;
    }

    int BNUM = (n + BSIZE - 1) / BSIZE;

    for (int i = 0; i < BNUM; i++) {
        block[i].init(i * BSIZE, min(n - 1, (i + 1) * BSIZE - 1));
    }

    while (q--) {
        scanf("%d%d%d", &type, &x, &y);

        x--, y--;

        if (type == 1) {
            query1(x, y);
        } else if (type == 2) {
            query2(x, y);
        } else {
            if (query3(x, y)) {
                ss << "YES" << endl;
            } else {
                ss << "NO" << endl;
            }
        }
    }

    cout << ss.str() << endl;
    
    return 0;
}
                             