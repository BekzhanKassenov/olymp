/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <bits/stdc++.h>

using namespace std;

#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 60;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
vector <int> g[MAXN];
int a[MAXN];

long long dfs(int v) {
    long long ans = 0;
    for (int to : g[v]) {
        ans += 2 * dfs(to);
    }

    return ans + a[v];
}


int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        g[i].resize(k);

        for (int& x : g[i]) {
            cin >> x;
        }
    }

    cout << sum << ' ' << dfs(1) << endl;
    
    return 0;
}
