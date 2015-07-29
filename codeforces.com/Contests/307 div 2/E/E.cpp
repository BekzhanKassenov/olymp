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
const int MAXN = 500010;
const int BSIZE = 710;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

long long a[MAXN];
pair <long long, int> b[MAXN];
int BNUM;

bool cmp(const pair <long long, int>& l, const pair <long long, int>& r) {
    return l.first < r.first;
}

void combine(pair <int, int>& l, const pair <int, int>& r) {
    if (l.first == -1) {
        l = r;
        return;
    }

    if (r.first == -1) {
        return;
    }

    l.first = min(l.first, r.first);
    l.second = max(l.second, r.second);
}

struct Block {
    int l, r;
    long long addend;

    void apply(int l, int r, long long val) {
        for (int i = l; i <= r; i++) {
            a[i] += val;
        }

        build();
        addend = 0;
    }

    void build() {
        for (int i = l; i <= r; i++) {
            a[i] += addend;
        }

        for (int i = l; i <= r; i++) {
            b[i].first = a[i];
            b[i].second = i;
        }

        sort(b + l, b + r + 1);
    }

    pair <int, int> get(long long val) {
        long long to_search = val - addend;

        int left = lower_bound(b + l, b + r + 1, make_pair(to_search, 0), cmp) - b;

        if (left == r + 1 || b[left].first != to_search) {
            return make_pair(-1, -1);
        }

        int right = upper_bound(b + l, b + r + 1, make_pair(to_search, 0), cmp) - b - 1;

        return make_pair(b[left].second, b[right].second);
    }
};

Block block[BSIZE];
int n, q, type;
int l, r;
long long x;

void update(int l, int r, long long val) {
    int block_l = l / BSIZE;
    int block_r = r / BSIZE;

    if (block_l == block_r) {
        block[block_l].apply(l, r, val);
        return;
    }

    block[block_l].apply(l, block[block_l].r, val);
    block[block_r].apply(block[block_r].l, r, val);

    for (int i = block_l + 1; i < block_r; i++) {
        block[i].addend += val;
    }
}

int get(long long val) {
    pair <int, int> result(-1, -1);
    for (int i = 0; i < BNUM; i++) {
        combine(result, block[i].get(val));
    }

    if (result.first == -1) {
        return -1;
    }

    return result.second - result.first;
}

char result[MAXN * 10];
int lastres;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &q);

    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
    }

    BNUM = (n + BSIZE - 1) / BSIZE;

    for (int i = 0; i < BNUM; i++) {
        block[i].l = i * BSIZE;
        block[i].r = min((i + 1) * BSIZE, n) - 1;
        block[i].build();
    }

    while (q--) {
        scanf("%d", &type);

        if (type == 1) {
            scanf("%d%d%I64d", &l, &r, &x);
            update(l - 1, r - 1, x);
        } else {
            scanf("%I64d", &x);
            sprintf(result + lastres, "%d\n", get(x));

            while (result[lastres]) {
                lastres++;
            }
        }
    }

    puts(result);
    
    return 0;
}
