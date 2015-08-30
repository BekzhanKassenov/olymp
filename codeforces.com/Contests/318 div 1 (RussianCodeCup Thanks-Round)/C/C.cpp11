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

int n, x, y;
vector <int> g[MAXN];
bool dpPar[MAXN], ans;
vector <bool> dp[MAXN];

// Check whether node can be placed to the one line
bool canPar[MAXN];
vector <bool> can[MAXN];

void dfsPar(int v, int par = -1) {
    dpPar[v] = true;
    canPar[v] = true;

    int cnt = 0;
    for (int& to: g[v]) {
        if (to != par) {
            dfsPar(to, v);
            
            dpPar[v] &= dpPar[to];
            canPar[v] &= canPar[to];

            if (!canPar[to]) {
                cnt++;
            }
        }
    }

    if (par != -1) {
        dpPar[v] &= (cnt <= 1);
    } else {
        dpPar[v] &= (cnt <= 2);
    }
    canPar[v] &= (g[v].size() <= 2);
}

void dfsDp(int v, int par = -1, int idx = -1) {
    int sumDp = 0;
    int sumCan = 0;
    int size = g[v].size();

    if (par != -1) {
        sumDp += dp[par][idx];
        sumCan += can[par][idx];
        size++;
    }

    for (int& to: g[v]) {
        if (to != par) {
            sumDp += dpPar[to];
            sumCan += canPar[to];
        }
    }

    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to != par) {
            sumDp -= dpPar[to];
            sumCan -= canPar[to];
            
            dp[v][i] = (sumDp == size - 1) && (sumCan >= size - 2);

            sumDp += dpPar[to];
            sumCan += canPar[to];
        }
    }

    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to != par) {
            dfsDp(to, v, i);
        }
    }

    ans |= (sumCan >= size - 2) && (sumDp == size);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        dp[i].resize(g[i].size());
        can[i].resize(g[i].size());
    }

    dfsPar(1);

    dfsDp(1);

    if (ans) {
        puts("Yes");
    } else {
        puts("No");
    }

    return 0;
}
