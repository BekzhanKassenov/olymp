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
typedef pair <long long, set <long long> > Pair;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

void merge(Pair& a, Pair& b) {
    if (a.second.size() < b.second.size()) {
        merge(b, a);
        return;
    }

    long long delta = b.first - a.first;
    for (int x : b.second) {
        a.second.insert(x + delta);
    }
}

int n;
vector <int> child[MAXN];
Pair ans[MAXN];
int delta[MAXN];
int joy[MAXN];
int res[MAXN];

void dfs(int v) {
    int mx = -1;
    for (int to : child[v]) {
        dfs(to);
        if (mx == -1 || ans[to].second.size() > ans[mx].second.size()) {
            mx = to;
        }
    }

    if (mx != -1) {
        swap(ans[v].first, ans[mx].first);
        ans[v].second.swap(ans[mx].second);
        for (int to : child[v]) {
            if (to != mx) {
                merge(ans[v], ans[to]);
            }
        }
    }

    ans[v].second.insert(joy[v] - ans[v].first);
    res[v] = ans[v].second.size();
    ans[v].first += delta[v];
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &joy[i]);
    }

    int start = -1;
    for (int i = 1; i <= n; i++) {
        int par;
        scanf("%d", &par);
        if (par == 0) {
            start = i;
        } else {
            child[par].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &delta[i]);
    }

    dfs(start);
    
    for (int i = 1; i <= n; i++) {
        printf("%d\n", res[i]);
    }
    
    return 0;
}
