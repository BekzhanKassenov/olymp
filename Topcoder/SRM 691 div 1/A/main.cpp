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
const int MAXN = 55;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
vector <int> g;
int parent[MAXN];
bool used[MAXN];

int getParent(int v) {
    if (parent[v] == v) {
        return v;
    }

    return parent[v] = getParent(parent[v]);
}

void unite(int a, int b) {
    parent[getParent(a)] = getParent(b);
}

int last;
int dfs(int v) {
    last = v;
    if (used[v]) {
        return 0;
    }

    used[v] = true;
    return dfs(g[v]) + 1;
}

bool onCycle(int node, int v, int d = 0) {
    if (d == 2 * n) {
        return false;
    }

    if (v == node && d != 0) {
        return true;
    }

    return onCycle(node, g[v], d + 1);
}

long long solve(const vector <int>& a) {
    n = a.size();
    g = a;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < n; i++) {
        unite(i, a[i]);
    }

    if (getParent(0) == getParent(1)) {
        if (onCycle(0, 0) && onCycle(1, 1)) {
            return 1ll << n;
        }

        if (onCycle(0, 0) && !onCycle(1, 1)) {
            int cnt = dfs(1);

            return (1LL << (n - cnt)) * ((1LL << cnt) - 1);
        }

        if (!onCycle(0, 0) && onCycle(1, 1)) {
            int cnt = dfs(0);

            return (1LL << (n - cnt)) * ((1LL << cnt) - 1);
        }

        dfs(0);
        dfs(1);
        int lca = last;

        memset(used, false, sizeof used);
        int cntComm = dfs(lca);

        int cnt0 = dfs(0);
        int cnt1 = dfs(1);
        int rest = n - cntComm - cnt0 - cnt1;

        long long ans = 1LL << n;
        ans -= ((1LL << cnt0) - 1) * (1LL << rest);
        ans -= ((1LL << cnt1) - 1) * (1LL << rest);

        return ans;

    }

    int cnt1 = dfs(0);
    int cnt2 = dfs(1);

    return (1LL << (n - cnt1 - cnt2)) * ((1LL << cnt1) - 1) * ((1LL << cnt2) - 1);
}

class Sunnygraphs {
public:
    long long count(const vector <int>& a) {
        return solve(a);
    }
};

int main() {
    cout << solve({2, 2, 3, 4, 3}) << endl;
}

