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

int n, m;
int x, y;
vector <int> g[MAXN];
bool attacked[MAXN];
bool has[MAXN];

long long innerDP[MAXN];
long long outerDP[MAXN];

int innerFar[MAXN];
int outerFar[MAXN];

void dfsInner(int v, int par = -1) {
    if (attacked[v]) {
        has[v] = true;
    }

    for (int to: g[v]) {
        if (to != par) {
            dfsInner(to, v);

            if (has[to]) {
                has[v] = true;
                innerDP[v] += innerDP[to] + 2;
                innerFar[v] = max(innerFar[v], innerFar[to] + 1);
            }
        }
    }
}

void dfsOuter(int v, bool hasOut = false, int par = -1) {
    int max1 = -2, max2 = -2;
    int cnt = 0;

    for (auto to: g[v]) {
        if (to == par) {
            continue;
        }
        
        if (innerFar[to] >= max1) {
            max2 = max1;
            max1 = innerFar[to];
        } else if (innerFar[to] >= max2) {
            max2 = innerFar[to];
        }

        if (has[to]) {
            cnt++;
        }
    }


    hasOut |= attacked[v];

    cnt--;
    for (int to: g[v]) {
        if (to != par && has[to]) {
            if (hasOut || cnt > 0) {
                outerDP[to] = 2;
            }

            if (hasOut) {
                outerDP[to] += outerDP[v];
                outerFar[to] = outerFar[v] + 1;
            }

            if (cnt > 0) {
                outerDP[to] += innerDP[v] - innerDP[to] - 2;

                if (max1 == innerFar[to]) {
                    outerFar[to] = max(outerFar[to], max2 + 2);
                } else {
                    outerFar[to] = max(outerFar[to], max1 + 2);
                }
            }

            dfsOuter(to, cnt > 0 || hasOut,  v);
        }
    }   
}

long long f(int num) {
    return innerDP[num] + outerDP[num] - max(innerFar[num], outerFar[num]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        attacked[x] = true;
    }

    dfsInner(1);
    dfsOuter(1);

    /*
    for (int i = 1; i <= n; i++) {
        cerr << innerDP[i] << ' ';
    }
    cerr << endl;

    for (int i = 1; i <= n; i++) {
        cerr << outerDP[i] << ' ';
    }
    cerr << endl;

    for (int i = 1; i <= n; i++) {
        cerr << innerFar[i] << ' ';
    }
    cerr << endl;

    for (int i = 1; i <= n; i++) {
        cerr << outerFar[i] << ' ';
    }
    cerr << endl;
    */

    int res = -1;
    for (int i = 1; i <= n; i++) {
        if (has[i] && (res == -1 || f(res) > f(i))) {
            res = i;
        }
    }

    printf("%d\n%I64d\n", res, f(res));
    return 0;
}
