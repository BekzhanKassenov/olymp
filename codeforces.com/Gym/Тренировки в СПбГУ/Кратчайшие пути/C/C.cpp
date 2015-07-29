#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define PII pair <int, int>
#define MP make_pair
#define F first
#define S second

const int maxn = 2010;
const double INF = 1e18;

vector <PII> g[maxn];

int x, y, cost, used[maxn];
double dist[maxn];
bool inque[maxn];

int main() {
	freopen("maze.in", "r", stdin);
	freopen("maze.out", "w", stdout);

	int n, m;

	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &x, &y, &cost);

		if (x == y && cost > 0) {
			puts(":)");
			return 0;
		} else 
			if (x != y)
				g[--x].push_back(MP(cost * -1, --y));
	}

	for (int i = 0; i < n; i++)
		dist[i] = INF;

	queue <int> q;
	q.push(0);
	dist[0] = 0;
	inque[0] = true;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		inque[v] = false;

		for (size_t i = 0; i < g[v].size(); i++) {
			int to = g[v][i].S;

			if (dist[to] > dist[v] + g[v][i].F) {
				dist[to] = max(dist[v] + g[v][i].F, -INF);

				if (used[to] > 2 * n) {
					puts(":)");
					return 0;
				}

				if (!inque[to]) {
					used[to]++;
					inque[to] = true;
					q.push(to);
				}
			}
		}
	}

	if (dist[n - 1] == INF)
		puts(":(");
	else
		cout << -dist[n - 1];	

}
