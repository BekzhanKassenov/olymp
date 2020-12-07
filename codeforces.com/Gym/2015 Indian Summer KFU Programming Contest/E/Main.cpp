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
const int MAXN = 120010;
const int BSIZE = 340;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int a[MAXN];
int block[BSIZE][26];

void reset(int bnum) {
    for (int i = 0; i < 26; i++) {
        block[bnum][i] = i;
    }
}

void apply_to_block(int row, int from, int to) {
    for (int i = 0; i < 26; i++) {
        if (block[row][i] == from) {
            block[row][i] = to;
        }
    }
}

void flush_block(int bnum) {
    for (int i = BSIZE * bnum; i < BSIZE * (bnum + 1); i++) {
        a[i] = block[bnum][a[i]];
    }
    reset(bnum);
}

void naive(int l, int r, int from, int to) {
    for (int i = l; i <= r; i++) {
        if (a[i] == from) {
            a[i] = to;
        }
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - 'a';
    }

    for (int i = 0; i < BSIZE; i++) {
        reset(i);
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int l, r;
        char cfrom, cto;
        cin >> l >> r >> cfrom >> cto;
        int from = cfrom - 'a';
        int to = cto - 'a';
        l--, r--;

        int lblock = l / BSIZE;
        int rblock = r / BSIZE;
        if (lblock == rblock) {
            flush_block(lblock);
            naive(l, r, from, to);
            continue;
        }

        if (l % BSIZE != 0) {
            flush_block(lblock);
            naive(l, BSIZE * (lblock + 1) - 1, from, to);
            lblock++;
        }
        if (r % BSIZE != BSIZE - 1) {
            flush_block(rblock);
            naive(BSIZE * rblock, r, from, to);
            rblock--;
        }

        for (int bnum = lblock; bnum <= rblock; bnum++) {
            apply_to_block(bnum, from, to);
        }
    }

    for (int i = 0; i < BSIZE; i++) {
        flush_block(i);
    }

    for (int i = 0; i < n; i++) {
        putchar(a[i] + 'a');
    }

    puts("");
    return 0;
}
