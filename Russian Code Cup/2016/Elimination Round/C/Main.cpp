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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n;
vector <int> g[MAXN];
int innerDP[MAXN], outerDP[MAXN];
int innerMax1[MAXN], innerMax2[MAXN];
int dp[MAXN];
int depth[MAXN];

void dfsInner(int v, int par = -1) {
    innerDP[v] = 0;
    innerMax1[v] = innerMax2[v] = -1;

    for (int to: g[v]) {
        if (to != par) {
            depth[to] = depth[v] + 1;
            dfsInner(to, v);
            innerDP[v] = max(innerDP[v], innerDP[to] + 1);

            if (innerMax1[v] == -1 || innerDP[innerMax1[v]] < innerDP[to]) {
                innerMax2[v] = innerMax1[v];
                innerMax1[v] = to;
            } else if (innerMax2[v] == -1 || innerDP[innerMax2[v]] < innerDP[to]) {
                innerMax2[v] = to;
            }
        }   
    }
}

void dfsOuter(int v, int par = -1) {
    outerDP[v] = 0;
    if (par != -1) {
        int mx = innerMax1[par];
        if (innerMax1[par] == v) {
            mx = innerMax2[par];
        }

        outerDP[v] = outerDP[par] + 1;

        if (mx != -1) {
            outerDP[v] = max(outerDP[v], innerDP[mx] + 2);
        }
    }
    
    for (int to: g[v]) {
        if (to != par) {
            dfsOuter(to, v);
        }
    }
}

long long binpow(long long base, long long p) {
    long long ans = 1;
    while (p > 0) {
        if (p & 1) {
            ans = (ans * base) % MOD;
        }

        base = (base * base) % MOD;
        p >>= 1;
    }

    return ans;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        for (int i = 0; i <= n; i++) {
            g[i].clear();
        }   

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

        depth[1] = 0;
        dfsInner(1);
        dfsOuter(1);

        dp[1] = innerDP[1];
        for (int i = 2; i <= n; i++) {
            dp[i] = max(innerDP[i], outerDP[i]);
        }

        bool bad = false;
        int ansV = -1;
        int ansD = -1;
        for (int i = 1; i <= n; i++) {
            if (g[i].size() < 3u) {
                if (ansD == -1 || ansD > dp[i]) {
                    ansD = dp[i];
                    ansV = i;
                }
            } else if (g[i].size() > 3u) {
                bad = true;
            }
        }

        if (ansD == -1 || bad) {
            puts("-1");
        } else {
            ansD = ((binpow(2, ansD + 1) - n - 1) + MOD) % MOD;
            printf("%d %d\n", ansV, ansD);
        }
    }
    
    return 0;
}
