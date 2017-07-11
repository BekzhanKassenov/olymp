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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

vector <int> layer[MAXN];
stringstream gr;
vector <int> g[MAXN];
int dist[MAXN];
bool used[MAXN];

void edge(int u, int v) {
    gr << u << ' ' << v << endl;
    g[u].push_back(v);
    g[v].push_back(u);
}

void bfs(int s) {
    queue <int> q;
    q.push(s);
    memset(used, false, sizeof used);
    used[s] = true;
    memset(dist, -1, sizeof dist);
    dist[s] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (!used[to]) {
                used[to] = true;
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int n, k;
    cin >> n >> k;

    int cur = n;

    int l = 0;
    while (cur > k) {
        for (int i = 0; i < k; i++) {
            layer[l].push_back(cur--);
        }
        l++;
    }


    if (cur > 2) {
        while (cur > 1) {
            layer[l].push_back(cur--);
        }

        l++;
    } else if (cur == 2) {
        vector <int> vec = {1, 2};
        for (int i = 0; i < l; i++) {
            vec.push_back(layer[i].back());
            layer[i].pop_back();
        }

        for (size_t j = 1; j < vec.size(); j++) {
            edge(vec[j], vec[j - 1]);
        }
    }

    layer[l].push_back(1);

    for (int i = 0; i < l; i++) {
        for (size_t j = 0; j < layer[i].size(); j++) {
            if (j < layer[i + 1].size()) {
                edge(layer[i][j], layer[i + 1][j]);
            } else {
                edge(layer[i][j], layer[i + 1].back());
            }
        }
    }

    bfs(1);
    int v = 1;
    for (int i = 2; i <= n; i++) {
        if (dist[i] > dist[v]) {
            v = i;
        }
    }

    bfs(v);
    v = 1;
    for (int i = 2; i <= n; i++) {
        if (dist[i] > dist[v]) {
            v = i;
        }
    }

    cout << dist[v] << endl << gr.str() << endl;    
    
    return 0;
}
