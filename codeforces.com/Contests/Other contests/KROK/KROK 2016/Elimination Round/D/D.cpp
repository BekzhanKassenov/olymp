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

int n, m;
pair <int, int> edge[MAXN];
vector <int> out[MAXN];
int in[MAXN];
bool used[MAXN];

bool dfs(int v) {
    used[v] = true;

    int nxt = -1;
    for (int to: out[v]) {
        in[to]--;
        if (in[to] == 0) {
            if (nxt != -1) {
                return false;
            }

            nxt = to;
        }
    }

    if (nxt == -1) {
        return true;
    }

    return dfs(nxt);
}

bool check(int len) {
    for (int i = 1; i <= n; i++) {
        out[i].clear();
        in[i] = 0;
    }

    memset(used, false, sizeof(used[0]) * (n + 1));

    for (int i = 0; i < len; i++) {
        out[edge[i].first].push_back(edge[i].second);
        in[edge[i].second]++;
    }

    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            if (!dfs(i)) {
                return false;
            }

            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            return false;
        }
    }

    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &edge[i].first, &edge[i].second);
    }

    int l = 0, r = m - 1;
    int ans = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid + 1)) {
            ans = mid + 1;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}
