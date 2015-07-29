#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair

int dx[4] = {0, 0, 1, 1};
int dy[4] = {0, 1, 0, 1};
int n, m, k, x, y, t;
bool used[100][100];

bool ok(int _x, int _y) {
	return (_x >= 0 && _x < n && _y >= 0 && _y < m);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> m >> k;

	int ans = 0;

	while (k--) {
		cin >> t >> x >> y;

		x--, y--, t--;

		vector <PII> pl;

		bool flag = true;

		for (int i = 0; i < 4; i++) {
			if (i != t) {
				PII temp = MP(x + dx[i], y + dy[i]);
				                    
				if (ok(temp.F, temp.S) && !used[temp.F][temp.S]) {
					pl.push_back(temp);
				} else {
					flag = false;
				}
			}
		}

		if (flag) {
			ans += 3;

			for (int i = 0; i < 3; i++)
				used[pl[i].F][pl[i].S] = true;
		}
	}

	cout << ans;

	return 0;
}
