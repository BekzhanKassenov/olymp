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
const int MAXN = 200010;
const int BSIZE = 450;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Block {
    int a[BSIZE];
    int left, right;
    int taskl, taskr;
    bool dead;

    Block() :
        taskl(-1),
        taskr(-1),
        dead(false) { }

    void query(int task) {
        if (taskl == -1) {
            taskl = taskr = task;
        } else {
            if (taskr + 1 == task) {
                taskr++;
            } else {
                taskl = -1, taskr = -1;
                dead = true;
            }
        }
    }

    void apply() {
        if (dead) {
            for (int i = 0; i < right - left + 1; i++) {
                a[i] = -1;
            }
        } else if (taskl != -1) {
            for (int i = 0; i < right - left + 1; i++) {
                if (a[i] + 1 == taskl) {
                    a[i] = taskr;
                } else {
                    a[i] = -1;
                }
            }
        }

        taskl = taskr = -1;
    }

    void query(int l, int r, int task) {
        apply();

        for (int i = l - left; i <= r - left; i++) {
            if (a[i] + 1 == task) {
                a[i]++;
            } else {
                a[i] = -1;
            }
        }
    }
};

int n, k, q;
Block b[BSIZE];

void query(int l, int r, int task) {
    int lblock = l / BSIZE;
    int rblock = r / BSIZE;

    if (lblock == rblock) {
        b[lblock].apply();
        b[lblock].query(l, r, task);
        return;
    }

    b[lblock].apply();
    b[rblock].apply();

    b[lblock].query(l, b[lblock].right, task);
    b[rblock].query(b[rblock].left, r, task);

    for (int i = lblock + 1; i < rblock; i++) {
        b[i].query(task);
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);
    scanf("%d", &q);

    for (int i = 0; i < n; i += BSIZE) {
        b[i / BSIZE].left = i;
        b[i / BSIZE].right = min(i + BSIZE - 1, n - 1);
    }

    while (q--) {
        int l, r, task;
        scanf("%d%d%d", &l, &r, &task);

        query(l - 1, r - 1, task);
    }

    int ans = 0;
    for (int i = 0; i < n; i += BSIZE) {
        int bnum = i / BSIZE;
        b[bnum].apply();

        for (int j = 0; j < b[bnum].right - b[bnum].left + 1; j++) {
            if (b[bnum].a[j] == k) {
                ans++;
            }
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
