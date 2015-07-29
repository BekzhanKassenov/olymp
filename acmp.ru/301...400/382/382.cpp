#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define PII pair <int, int>
#define x first
#define y second
#define MP make_pair

char c[100][100];

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int cnt[100][100], n;
bool used[100][100];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n;

	memset(c, '#', sizeof c);

	for (int i = 1; i <= n; i++) {
	  	for (int j = 1; j <= n; j++)
	  		cin >> c[i][j];
	}

	queue <PII> q;
	q.push(MP(1, 1));
	used[1][1] = true;
	q.push(MP(n, n));
	used[n][n] = true;

	while (!q.empty()) {
		PII cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			PII tmp(cur.x + dx[i], cur.y + dy[i]);

			if (!used[tmp.x][tmp.y]) {
				if (c[tmp.x][tmp.y] == '#') {
					cnt[tmp.x][tmp.y]++;
				} else {
					used[tmp.x][tmp.y] = true;
					q.push(tmp);
				}
			}
		}
	}

	int ans = 0;

	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= n + 1; j++) 
			ans += cnt[i][j];

	ans -= 4;

	cout << ans * 5 * 5;	

	return 0;
}
