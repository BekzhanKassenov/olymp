#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int n, m;

int dx[8] = {1, 0, 0, -1, 1,  1, -1, -1};
int dy[8] = {0, 1, -1, 0, 1, -1,  1, -1};
char tp[8] = {'|', '-', '-', '|', 92, '/', '/', 92};

bool ans = true;

bool used[200][200];
int tin[200][200], fup[200][200];

int timer = 0;

vector <string> a;

bool is_edge(char c) {
 	return (c == '|' || c == 92 || c == '/' || c == '-');
}

bool ok(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

void get_neib(int x, int y, char c, int& x1, int& y1, int& x2, int& y2) {
	if (c == '-') {
	 	x1 = x, y1 = y - 1;
	 	x2 = x, y2 = y + 1;
	}	

	if (c == '|') {
		x1 = x - 1, y1 = y;
		x2 = x + 1, y2 = y;
	}

	if (c == '/') {
		x1 = x + 1, y1 = y - 1;
		x2 = x - 1, y2 = y + 1;
	}

	if (c == 92) {
		x1 = x - 1, y1 = y - 1;
		x2 = x + 1, y2 = y + 1;
	}

}

bool check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i & 1) == 0 && (j & 1) == 0 && a[i][j] != 'O')
				return false;

			if (a[i][j] == 'O') {
				if ((i & 1) == 1 || (j & 1) == 1)
					return false;

				int cnt = 0;

				for (int k = 0; k < 8; k++) {
					int tmpx = i + dx[k];
					int tmpy = j + dy[k];

					if (ok(tmpx, tmpy) && a[tmpx][tmpy] == tp[k])
						cnt++;
				}

				if (cnt != 3)
					return false;

		 	}

		 	if (is_edge(a[i][j])) {
		 		int x1, x2, y1, y2;
		 		get_neib(i, j, a[i][j], x1, y1, x2, y2);

		 		if (!ok(x1, y1) || !ok(x2, y2) || a[x1][y1] != 'O' || a[x2][y2] != 'O')
		 			return false;
		 	}

		 	if (!is_edge(a[i][j]) && a[i][j] != 'O' && a[i][j] != ' ')
		 		return false;
		}
	}

	return true;
}

void dfs(int x, int y, int px = -1, int py = -1) {
	used[x][y] = 1;

	tin[x][y] = fup[x][y] = timer++;

	for (int i = 0; i < 8; i++) {
		int tmpx = x + dx[i];
		int tmpy = y + dy[i];

		if (ok(tmpx, tmpy) && a[tmpx][tmpy] == tp[i]) {
			tmpx += dx[i];
			tmpy += dy[i];

			if (tmpx == px && tmpy == py)
				continue;

			if (!used[tmpx][tmpy]) {
				dfs(tmpx, tmpy, x, y);
				fup[x][y] = min(fup[x][y], fup[tmpx][tmpy]);

				if (fup[tmpx][tmpy] > tin[x][y])
					ans = false;

			} else 
				fup[x][y] = min(fup[x][y], tin[tmpx][tmpy]);
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> m >> n;

	a.resize(n);

	getline(cin, a[0]);

	for (int i = 0; i < n; i++)
		getline(cin, a[i]);

	if (!check()) {
		puts("Just a picture");
		return 0;	
	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j < m; j++)
	 		if (!used[i][j] && a[i][j] == 'O') {
	 			dfs(i, j);
	 			cnt++;
	 		}	
	}

	if (cnt > 1 || !ans)
		puts("Just a picture");
	else
		puts("Island world");

	return 0;	

}
