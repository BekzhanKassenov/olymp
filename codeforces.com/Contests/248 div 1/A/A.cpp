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

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

vector <int> adj[maxn];
int a[maxn], last, x, n, m;
ll ans, temp, sum;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d", &x);

        if (last == 0 || a[last - 1] != x)
            a[last++] = x;
    }

    m = last;

    for (int i = 1; i < m - 1; i++) {
        adj[a[i]].push_back(a[i + 1]);
        adj[a[i]].push_back(a[i - 1]);
    }

    if (m > 1) {
        adj[a[0]].push_back(a[1]);
        adj[a[m - 1]].push_back(a[m - 2]);
    }

    for (int i = 0; i < m - 1; i++) {
        sum += abs(a[i] - a[i + 1]);
    }

    ans = sum;

    for (int i = 1; i <= n; i++) {
        if (adj[i].empty())
            continue;

        sort(all(adj[i]));

        temp = sum;
        int mid = adj[i][adj[i].size() / 2];

        for (size_t j = 0; j < adj[i].size(); j++) {
            temp -= abs(adj[i][j] - i);
            temp += abs(adj[i][j] - mid);
        }

        ans = min(ans, temp);
    }

    printf("%I64d", ans);
    
    return 0;
}
