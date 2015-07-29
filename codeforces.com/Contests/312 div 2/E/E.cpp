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
const int MAXN = 100010;

#ifndef ONLINE_JUDGE
    const int BSIZE = 4;
#else
    const int BSIZE = 330;
#endif

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char s[MAXN];
int n, q;

struct Block {
    int l, r, len;
    int cnt[26];
    bool asc;
    bool sorted;

    // O(sqrt(N))
    void init(int l, int r) {
        memset(cnt, 0, sizeof cnt);
        asc = false;
        sorted = false;
        
        this->l = l;
        this->r = r;
        this->len = r - l + 1;

        for (int i = l; i <= r; i++) {
            cnt[s[i] - 'a']++;
        }
    }
    
    // Query inside of one block
    // O(sqrt(N) * log(sqrt(n))
    bool query(int l, int r, bool asc) {
        apply_sort();
        sorted = false;

        sort(s + l, s + r + 1);
        
        if (!asc) {
            reverse(s + l, s + r + 1);
        }
    }

    // O(sqrt(N) * alpha)
    void apply_sort() {
        if (!sorted) {
            return;
        }
        
        int pos = l;

        if (asc) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < cnt[i]; j++) {
                    s[pos++] = i + 'a';
                }
            }
        } else {
            for (int i = 25; i >= 0; i--) {
                for (int j = 0; j < cnt[i]; j++) {
                    s[pos++] = i + 'a';
                }
            }
        }
    }

    // O(alpha)
    void prepare_sort(int cnt[26], bool asc) {
        this->asc = asc;
        this->sorted = true;

        memset(this->cnt, 0, sizeof(this->cnt));

        if (asc) {
            for (int i = 0, cur = len; i < 26 && cur > 0; i++) {
                int num = min(cnt[i], cur);
                cnt[i] -= num;
                this->cnt[i] = num;
                cur -= num;
            }
        } else {
            for (int i = 25, cur = len; i >= 0 && cur > 0; i--) {
                int num = min(cnt[i], cur);
                cnt[i] -= num;
                this->cnt[i] = num;
                cur -= num;
            }
        }
    }

    // O(sqrt(N))
    void prepare_sort(int cnt[26], bool asc, int l, int r) {
        int pos = l;
        sorted = false;
        
        if (asc) {
            for (int i = 0; i < 26 && pos <= r; i++) {
                for (;cnt[i] > 0 && pos <= r; cnt[i]--, pos++) {
                   this->cnt[s[pos] - 'a']--;
                   
                   s[pos] = i + 'a';
                   this->cnt[s[pos] - 'a']++;
                }
            }
        } else {
            for (int i = 25; i >= 0 && pos <= r; i--) {
                for (;cnt[i] > 0 && pos <= r; cnt[i]--, pos++) {
                   this->cnt[s[pos] - 'a']--;
                   
                   s[pos] = i + 'a';
                   this->cnt[s[pos] - 'a']++;
                }
            }
        }
    }
};

Block block[330];

void query(int l, int r, bool asc) {
    if (l / BSIZE == r / BSIZE) {
        block[l / BSIZE].query(l, r, asc);
        return;
    }

    int cnt[26];
    memset(cnt, 0, sizeof cnt);

    int block_l = (l + BSIZE - 1) / BSIZE;
    int block_r = (r - BSIZE + 1) / BSIZE;

    // Counting sort
    if (l % BSIZE != 0) {
        block[l / BSIZE].apply_sort();

        for (int i = l; i % BSIZE != 0; i++) {
            cnt[s[i] - 'a']++;
        }
    }

    if (r % BSIZE != BSIZE - 1) {
        block[r / BSIZE].apply_sort();

        for (int i = r; i % BSIZE != BSIZE - 1; i--) {
            cnt[s[i] - 'a']++;
        }
    }

    for (int i = block_l; i <= block_r; i++) {
        for (int j = 0; j < 26; j++) {
            cnt[j] += block[i].cnt[j];
        }
    }

    // Apply sort to each block
    if (l % BSIZE != 0) {
        int bnum = l / BSIZE;
        block[bnum].prepare_sort(cnt, asc, l, block[bnum].r);
    }

    for (int i = block_l; i <= block_r; i++) {
        block[i].prepare_sort(cnt, asc);
    }

    if (r % BSIZE != BSIZE - 1) {
        int bnum = r / BSIZE;
        block[bnum].prepare_sort(cnt, asc, block[bnum].l, r);
    }
}

int x, y, asc;

void apply() {
    for (int i = 0; i * BSIZE < n; i++) {
        block[i].apply_sort();
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d %d\n", &n, &q);
    
    gets(s);

    for (int i = 0; i * BSIZE < n; i++) {
        block[i].init(i * BSIZE, min((i + 1) * BSIZE - 1, n - 1));
    }

    while (q--) {
        scanf("%d%d%d", &x, &y, &asc);
        query(x - 1, y - 1, asc);
    }

    apply();

    puts(s);
    
    return 0;
}