/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <iostream>
#include <vector>
#include <iomanip>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <ctime>
#include <string>
#include <sstream>
#include <math.h>
#include <stack>

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

int n, m, s, k;
vector <int> g[MAXN];
vector <int> cost[MAXN];
int a[MAXN];
int dist[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d%d", &n, &m, &k, &s);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto bfs = [&](int type) {
        for (int i = 1; i <= n; i++) {
            dist[i] = INF;
        }

        queue <int> q;
        for (int i = 1; i <= n; i++) {
            if (a[i] == type) {
                dist[i] = 0;
                q.push(i);
            }
        }

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int to : g[v]) {
                if (dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }
    };

    for (int type = 1; type <= k; type++) {
        bfs(type);

        for (int i = 1; i <= n; i++) {
            cost[i].push_back(dist[i]);
        }
    }

    for (int i = 1; i <= n; i++) {
        sort(all(cost[i]));
        int ans = 0;
        for (int j = 0; j < s; j++) {
            ans += cost[i][j];
        }
        printf("%d ", ans);
    }
    puts("");

    return 0;
}