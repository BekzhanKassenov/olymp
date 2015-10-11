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
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int BSIZE = 256;
const int MAXN = BSIZE * BSIZE;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int a[MAXN];

struct Block {
    int arr[BSIZE];
    int l, r;
    int len;
    int addend;

    void init(int l, int r) {
        this->l = l, this->r = r;
        len = r - l + 1;
        
        memcpy(arr, a + l, sizeof(int) * len);
        sort(arr, arr + len);

        addend = 0;
    }

    void add(int l, int r) {
        for (int i = l; i <= r; i++) {
            a[i]++;
        }

        memcpy(arr, a + this->l, sizeof(int) * len);
        sort(arr, arr + len);
    }

    int query(int val) const {
        int pos = upper_bound(arr, arr + len, val - addend) - arr;

        return pos;
    }
};  

int n, k, bnum;
Block block[BSIZE];
int perm[MAXN];

int query(int l, int r, int median) {
    int block_l = l / BSIZE;
    int block_r = r / BSIZE;

    if (block_l == block_r) {
        block[block_l].add(l, r);
    } else {
        block[block_l].add(l, block[block_l].r);
        block[block_r].add(block[block_r].l, r);

        for (int i = block_l + 1; i < block_r; i++) {
            block[i].addend++;
        }
    }

    int sum = 0;
    for (int i = 0; i < bnum; i++) {
        sum += block[i].query(median);
    }

    if (sum > n / 2) {
        return median;
    }

    return median + 1;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    while (scanf("%d%d", &n, &k) == 2) {
        if (n == 0 && k == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        bnum = (n + BSIZE - 1) / BSIZE;
        for (int i = 0; i < n; i += BSIZE) {
            block[i / BSIZE].init(i, min(n, i + BSIZE) - 1);
        }

        memcpy(perm, a, sizeof(int) * n);

        sort(perm, perm + n);
        int median = perm[n / 2];

        for (int i = 0; i < k; i++) {
            int l, r;
            scanf("%d%d", &l, &r);

            printf("%d\n", (median = query(l - 1, r - 1, median)));
        }
    }
    
    return 0;
}
