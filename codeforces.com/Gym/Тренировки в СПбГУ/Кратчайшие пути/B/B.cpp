#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 1010;
const int INF = (int)1e9;

vector <int> g[maxn];
queue <int> q;

int n, m, x, y, dist[maxn];
bool used[maxn];

int bfs(int v) {
 	for (int i = 0; i < n; i++) {
 		dist[i] = INF;
 		used[i] = false;
 	}

 	q.push(v);
 	dist[v] = 0;
 	used[v] = true;

 	while (!q.empty()) {
 		int cur = q.front();
 		q.pop();

 		for (size_t i = 0; i < g[cur].size(); i++) {
 			int to = g[cur][i];
 			if (!used[to]) {
 				q.push(to);
 				dist[to] = dist[cur] + 1;
 				used[to] = true;
 			}
 		}
 	}
 	int ans = 0;
 	for (int i = 0; i < n; i++)
 		ans += dist[i];

 	return ans;	
}

int main() {
	freopen("sumdist.in", "r", stdin);
	freopen("sumdist.out", "w", stdout);

	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		g[--x].push_back(--y);
		g[y].push_back(x);
	}
	int ans = 0;

	for (int i = 0; i < n; i++) 
		ans += bfs(i);

	cout << (ans >> 1);

	return 0;	
}
