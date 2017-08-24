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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}


int n;
int a[MAXN];

void compress() {
    vector <int> temp(a, a + n);
    sort(all(temp));
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(all(temp), a[i]) - temp.begin();
    }
}

stringstream ss;
bool used[MAXN];

void dfs(int v, vector <int>& comp) {
    used[v] = true;
    comp.push_back(v);
    if (!used[a[v]]) {
        dfs(a[v], comp);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    compress();

    vector <int> comp;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i, comp);
            ans++;
            ss << comp.size();
            for (int v : comp) {
                ss << ' ' << v + 1;
            }
            ss << endl;
            comp.clear();
        }
    }
    
    printf("%d\n", ans);
    puts(ss.str().c_str());

    return 0;
}
