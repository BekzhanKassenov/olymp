#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int g[110][110];

int n, m, s, p, q, len, color[110], dist[110];

bool used[110];

bool dfs(int v, int p = -1) {
	color[v] = 1;

	bool ans = false;

	for (int i = 0; i < n && !ans; i++) {
		if (g[v][i]) {
			if (!color[i])
				ans = dfs(i, v);
			else {
				if (color[i] == 1 && p != i)
					return true;
			}
		}
	}

	color[v] = 2;

	return false;
}

void dfs_dist(int v, int p = -1) {
	used[v] = true;

	for (int i = 0; i < n; i++)
		if (i != p && g[i][v]) {
			dist[i] = dist[v] + g[i][v];
			dfs_dist(i, v);
		}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	scanf("%d%d%d", &n, &m, &s);

	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &p, &q, &len);
		p--, q--;

		if (g[p][q] != 0 || p == q) {
			cout << "YES";
			return 0;
		} else
			g[p][q] = g[q][p] = len;
	}

	for (int i = 0; i < n; i++) {
		if (!color[i] && dfs(i)) {
			cout << "YES";
			return 0;
		}
	}

	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs_dist(i);

			int tmp = i;

			for (int j = 0; j < n; j++)
				if (dist[j] > dist[tmp])
					tmp = j;

			memset(dist, 0, sizeof dist);

			dfs_dist(tmp);

			for (int j = 0; j < n; j++)
				if (dist[j] >= s) {
					puts("YES");
					return 0;
				}

			memset(dist, 0, sizeof dist);
		}
	}

	puts("NO");
	return 0;
}