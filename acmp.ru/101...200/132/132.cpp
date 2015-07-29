#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int INF = (int)1e9;

int g[2010][2010], dist[2010], n, s, f;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> s >> f;

	for (int i = 0; i < n; i++) {
		dist[i] = INF;
		for (int j = 0; j < n; j++)
			cin >> g[i][j];
	}

	priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q;

	s--, f--;

	q.push(make_pair(0, s));
	dist[s] = 0;

	while (!q.empty()) {
	 	int v = q.top().second;
	 	int len = q.top().first;
	 	q.pop();

	 	for (int i = 0; i < n && len == dist[v]; i++)
	 		if (g[v][i] != -1 && len + g[v][i] < dist[i]) {
	 			dist[i] = len + g[v][i];
	 			q.push(make_pair(dist[i], i));
	 		}
	}

	if (dist[f] == INF)
		cout << -1;
	else
		cout << dist[f];

	return 0;	
}
