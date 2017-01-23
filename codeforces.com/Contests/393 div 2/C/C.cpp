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

int n;
int p[MAXN];
int b[MAXN];
bool used[MAXN];

void dfs(int v) {
    used[v] = true;
    if (!used[p[v]]) {
        dfs(p[v]);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        ans += x;
    }

    ans = 1 - ans % 2;

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i);
            cnt++;
        }
    }

    if (cnt > 1) {
        ans += cnt;
    }

    printf("%d\n", ans);

    return 0;
}
