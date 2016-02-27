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
const int MAXN = 210;
const int MAXC = 20010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int a[MAXN];
int mem[2][2 * MAXC];
int *dp[2];

bool ok(int num) {
    return -MAXC < num && num < MAXC;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < 2 * MAXC; i++) {
        mem[0][i] = mem[1][i] = INF;
    }

    dp[0] = mem[0] + MAXC;
    dp[1] = mem[1] + MAXC;

    struct State {
        int dist;
        int idx, num;

        bool operator < (const State& s) const {
            if (dist != s.dist) {
                return dist < s.dist;
            }

            if (num != s.num) {
                return num < s.num;
            }

            return idx < s.idx;
        }
    };

    set <State> q;
    for (int i = 0; i < n; i++) {
        dp[0][a[i]] = 1;
        q.insert({1, 0, a[i]});
    }

    while (!q.empty()) {
        int idx = q.begin()->idx;
        int num = q.begin()->num;
        q.erase(q.begin());

        int mul = (idx == 0) ? -1 : 1;
        for (int i = 0; i < n; i++) {
            int nidx = idx ^ 1;
            int nnum = num + mul * a[i];

            if (ok(nnum) && dp[nidx][nnum] > dp[idx][num] + 1) {
                q.erase({dp[nidx][nnum], nidx, nnum});
                dp[nidx][nnum] = dp[idx][num] + 1;
                q.insert({dp[nidx][nnum], nidx, nnum});
            }
        }
    }


    int Q;
    scanf("%d", &Q);

    while (Q--) {
        int s, t;
        scanf("%d%d", &s, &t);

        if (s == t) {
            puts("0");
            continue;
        }

        if ((s + t) % 2 == 1) {
            puts("-1");
            continue;
        }

        int ans = min(dp[0][(t + s) / 2], dp[1][(t - s) / 2]);
        if (ans != INF) {
            printf("%d\n", ans);
        } else {
            puts("-1");
        }
    }

    return 0;
}
