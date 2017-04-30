/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <bits/stdc++.h>

using namespace std;

#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXA = 1000010;
const int MAXN = 200010;
const int BSIZE = 450;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Query {
    int l, r;
    int pos;
    long long ans;
};

Query q[MAXN];

int n, Q;
int a[MAXN];
long long cnt[MAXA];
long long curAns;

inline void add(int pos) {
    int num = a[pos];
    curAns += (2 * cnt[num] + 1) * num;
    cnt[num]++;
}

inline void del(int pos) {
    int num = a[pos];
    curAns -= (2 * cnt[num] - 1) * num;
    cnt[num]--;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &Q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < Q; i++) {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].pos = i;
    }

    sort(q, q + Q, [](const Query& q1, const Query& q2) {
        if (q1.l / BSIZE != q2.l / BSIZE) {
            return q1.l / BSIZE < q2.l / BSIZE;
        }

        return q1.r < q2.r;
    });

    for (int i = q[0].l; i <= q[0].r; i++) {
        add(i);
    }
    q[0].ans = curAns;

    int curL = q[0].l, curR = q[0].r;
    for (int i = 1; i < Q; i++) {
        while (curL < q[i].l) del(curL++);
        while (curL > q[i].l) add(--curL);

        while (curR < q[i].r) add(++curR);
        while (curR > q[i].r) del(curR--);

        q[i].ans = curAns;
    }

    sort(q, q + Q, by(Query, pos));

    for (int i = 0; i < Q; i++) {
        printf("%lld\n", q[i].ans);
    }
    
    return 0;
}
