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

vector <int> g[MAXN];
int n, a, b;
int value[MAXN];

pair <long long, long long> dfs(int v, int pr = -1) {
    pair <long long, long long> result;

    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];

        if (to == pr)
            continue;

        pair <long long, long long> child(dfs(to, v));
        
        result.first = max(result.first, child.first);
        result.second = max(result.second, child.second);
    }

    long long current = value[v] + result.first - result.second;

    if (current < 0)
        result.first += abs(current);
    else
        result.second += abs(current);

    return result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        scanf("%d", &value[i]);

    pair <long long, long long> res(dfs(1));

    printf("%I64d\n", res.first + res.second);

    return 0;
}
