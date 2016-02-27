/****************************************
**          Solution by NU #2          **
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

int n;
int x[MAXN], y[MAXN];
int a[MAXN], b[MAXN];
int p[4];
vector <int> g[MAXN];
bool used[MAXN];

int dfs(int v) {
    used[v] = true;
    int ans = 1;
    for (int to: g[v]) {
        if (!used[to]) {
            ans += dfs(to);
        }
    }

    return ans;
}

bool check(int mid) {
    for (int i = 0; i < n; i++) {
        g[i].clear();
        used[i] = false;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            if (abs(x[i] - x[p[j]]) + abs(y[i] - y[p[j]]) >= mid) {
                g[p[j]].push_back(i);
                g[i].push_back(p[j]); 
            }
        }
    }

    return dfs(0) == n;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x[i], &y[i]);
        a[i] = i;
        b[i] = i;
    }

    sort(a, a + n, [](int p1, int p2) {
        return x[p1] + y[p1] < x[p2] + y[p2];
    });

    sort(b, b + n, [](int p1, int p2) {
        return x[p1] - y[p1] < x[p2] - y[p2];
    });

    p[0] = a[0];
    p[1] = a[n - 1];
    p[2] = b[0];
    p[3] = b[n - 1];
    
    int ans = 0;

    int l = 0, r = 2e9 + 100;

    while (l <= r) {
        int mid = l + (r - l) / 2;
                
        if (check(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}
