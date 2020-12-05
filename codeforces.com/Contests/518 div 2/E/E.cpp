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
 
int n, k;
vector <int> g[MAXN];
int children[MAXN];
int level[MAXN];
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
 
    cin >> n >> k;
    if (n < 3) {
        cout << "No" << endl;
        return 0;
    }
 
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
 
    queue <int> q;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1u) {
            q.push(i);
            level[i] = 1;
        } else {
            level[i] = -1;
        }
    }

    int max_level = -1;
    int cnt_max = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (level[v] > max_level) {
            max_level = level[v];
            cnt_max = 1;
        } else {
            cnt_max++;
        }

        for (int to : g[v]) {
            if (level[to] == level[v] - 1) {
                continue;
            }
            if (level[to] == -1) {
                q.push(to);
                level[to] = level[v] + 1;
            }
            if (level[to] != level[v] + 1) {
                cout << "No" << endl;
                return 0;
            }
            children[to]++;
        }
    }

    /*
    for (int L = 1; L <= k + 1; L++) {
        cout << "level " << L << ": ";
        for (int i = 1; i <= n; i++) {
            if (level[i] == L) {
                cout << i << " ";
            }
        }
        cout << endl;
    }*/

    if (max_level != k + 1 || cnt_max != 1) {
        cout << "No" << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (level[i] != 1 && children[i] < 3) {
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;
 
    return 0;
}
