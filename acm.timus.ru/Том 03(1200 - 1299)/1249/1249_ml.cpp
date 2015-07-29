#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int a[3010][3010];

bool used[3010][3010];

int n, m;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

bool ok(int x, int y) {
	return ((x >= 0) && (x < n) && (y >= 0) && (y < m));
}

void get(int& x, int& y, int xx, int yy) {
	while (ok(x + xx, y + yy) && (a[x + xx][y + yy] == 1))
		x += xx, y += yy;
}

int cnt(int x, int y) {
	int ans = 0;

	for (int i = 0; i < 4; i++) {
		int tmpx = x + dx[i];
		int tmpy = y + dy[i];

		if (ok(tmpx, tmpy) && (a[tmpx][tmpy] == 1))
			ans++;
	}

	return ans;
}

char c;
int res;

int read_int() {
	do {
		c = getchar();
	} while ((c < '0') || (c > '9'));

	res = 0;

	do {
		res = res * 10 + c - '0';
		c = getchar();
	} while ((c >= '0') && (c <= '9'));
	
	return res;
}

bool check(int x, int y, int x1, int y1) {
	for (int i = x; i <= x1; i++) {
		if (ok(i, y1 + 1) && (a[i][y1 + 1] == 1))
			return false;

		if (ok(i, y - 1) && (a[i][y - 1] == 1))
			return false;
	}

	for (int j = y; j <= y1; j++) {
		if (ok(x - 1, j) && (a[x - 1][j] == 1))
			return false;

		if (ok(x1 + 1, j) && (a[x1 + 1][j] == 1))
			return false;
	}

	for (int i = x; i <= x1; i++) {
		for (int j = y; j <= y1; j++) {
			if (a[i][j] == 0)
				return false;

			used[i][j] = true;
		}
	}

	return true;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	n = read_int(), m = read_int();

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			a[i][j] = read_int();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((a[i][j] == 1) && (!used[i][j])) {
				int x1 = i, y1 = j;
				get(x1, j, 1, 0);
				get(i, y1, 0, 1);

				//cout << "Check: " << i + 1 << ' ' << j + 1 << ' ' << x1 + 1 << ' ' << y1 + 1 << endl;

				if (!(check(i, j, x1, y1))) {
					puts("No");
					return 0;
				}
			}
		}
   	}

   	puts("Yes");
   	return 0;
}
