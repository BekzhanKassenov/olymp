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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

namespace Tree {
    int n;
    int a[MAXN];
    vector <int> g[MAXN];
    int innerDP[MAXN], outerDP[MAXN];

    void dfsInner(int v, int par = -1) {
        for (int to : g[v]) {
            if (to != par) {
                dfsInner(to, v);
                innerDP[v] = max(innerDP[v], innerDP[to] + 1);
            }
        }
    }

    void dfsOuter(int v, int par = -1) {
        int mx1 = -1, mx2 = -1;
        for (int to: g[v]) {
            if (to != par) {
                if (mx1 == -1 || innerDP[to] > mx1) {
                    mx2 = mx1;
                    mx1 = innerDP[to];
                } else if (mx2 == -1 || innerDP[to] > mx2) {
                    mx2 = innerDP[to];
                }
            }
        }

        for (int to: g[v]) {
            if (to != par) {
                outerDP[to] = outerDP[v] + 1;
                if (mx1 == innerDP[to]) {
                    if (mx2 != -1) {
                        outerDP[to] = max(outerDP[to], mx2 + 2);
                    }
                } else {
                    if (mx1 != -1) {
                        outerDP[to] = max(outerDP[to], mx1 + 2);
                    }
                }
            }
        }

        for (int to: g[v]) {
            if (to != par) {
                dfsOuter(to, v);
            }
        }
    }

    double readAndGetProb(int k) {
        scanf("%d", &n);
        for (int i = 2; i <= n; i++) {
            scanf("%d", &a[i]);
        }

        for (int i = 1; i <= n; i++) {
            g[i].clear();
            innerDP[i] = 0;
            outerDP[i] = 0;
        }

        for (int i = 2; i <= n; i++) {
            g[i].push_back(a[i]);
            g[a[i]].push_back(i);
        }

        dfsInner(1);
        dfsOuter(1);

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int dp = max(innerDP[i], outerDP[i]);

            if (dp <= k) {
                ans++;
            }
        }

        return (double(ans)) / n;
    }
}

int T;
double E[25];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T--) {
        int C, K;
        scanf("%d%d", &C, &K);
        
        for (int i = 0; i < C; i++) {
            double p = Tree::readAndGetProb(K);
            double prev = 0;
            if (i > 0) {
                prev = E[i - 1];
            }

            E[i] = prev / p  + 4 / p - 3;
        }

        printf("%.14lf\n", E[C - 1]);
    }
    
    return 0;
}
