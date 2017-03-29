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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k;
int a[MAXN * MAXN];
int mem[3 * MAXN];
int *dp = mem + (MAXN + MAXN / 2);

bool ok(int v) {
    return -MAXN <= v && v <= MAXN;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int i = 0; i < k; i++) {
        scanf("%d", &a[i]);
        a[i] -= n;
        if (a[i] == 0) {
            printf("%d\n", 1);
            return 0;   
        }
    }

    sort(a, a + k);
    k = unique(a, a + k) - a;

    for (int i = 0; i < 3 * MAXN; i++) {
        mem[i] = INF;
    }

    queue <int> q;
    for (int i = 0; i < k; i++) {
        dp[a[i]] = 1;
        q.push(a[i]);
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 0; i < k; i++) {
            int to = v + a[i];
            if (ok(to) && dp[to] > dp[v] + 1) {
                dp[to] = dp[v] + 1;
                q.push(to);
            }
        }   
    }

    if (dp[0] == INF) {
        puts("-1");
        return 0;
    }

    printf("%d\n", dp[0]);

    return 0;
}
