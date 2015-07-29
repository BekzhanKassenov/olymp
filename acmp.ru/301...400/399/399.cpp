#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1,  0, -1};

const int INF = (int)1e9;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair

bool bfs(const vector <vector <int> >& g, int n, int m) {
	vector <vector <bool> > used(n, vector <bool> (m));

	queue <PII> q;

	q.push(MP(1, 1));

	used[1][1] = true;

	while (!q.empty()) {
	 	PII cur = q.front();
	 	q.pop();

	 	for (int i = 0; i < 4; i++) {
	 		PII tmp(cur.F + dx[i], cur.S + dy[i]);

	 		if (!used[tmp.F][tmp.S] && g[tmp.F][tmp.S] != INF) {
	 			used[tmp.F][tmp.S] = true;
	 			q.push(tmp);
	 		}
	 	}
	}

	return used[n - 2][m - 2];
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;

	cin >> n >> m;

	char c;

	getchar();

	vector <vector <int> > a(n, vector <int> (m));

	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j < m; j++) {
	 		c = getchar();
	 		if (c == '@') 
	 			a[i][j] = INF;
	 		else
	 			a[i][j] = 0;
	 	}
	 	c = getchar();
	}

	if (!bfs(a, n, m)) {
		cout << -1;
		return 0;
	}

	int x = 1, y = 1;

	int dir = 0;

	int cnt = 0;

	while (true) {
		if (x == n - 2 && y == m - 2)
			break;

		if (cnt > 10000000) {
			cout << -1;
			return 0;
		}

		cnt++;

		a[x][y]++;

		int mn = INF;

		for (int i = 0; i < 4; i++) {
			int t_x = x + dx[i];
			int t_y = y + dy[i];

			mn = min(mn, a[t_x][t_y]);
		}

		vector <int> v;

		for (int i = 0; i < 4; i++) {
			int t_x = x + dx[i];
			int t_y = y + dy[i];

			if (a[t_x][t_y] == mn)
				v.push_back(i);
		}

		if (find(v.begin(), v.end(), dir) == v.end())
			dir = v[0];

	   	x += dx[dir];
	   	y += dy[dir];
	}

	cout << cnt << endl;
}
