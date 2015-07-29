#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

int n, w, l, x, y, a[2013][2013];

int sum(int x, int y, int x1, int y1) {
	return a[x1][y1] - a[x1][y - 1] - a[x - 1][y1] + a[x - 1][y - 1];
}

bool check(int len) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int i1 = i + len - 1;
			int j1 = j + len - 1;

			if (i1 <= n && j1 <= n && sum(i, j, i1, j1) <= l) 
				return true;
		}
	}

	return false;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio(false);

	int t;
	cin >> t;

	while (t--) {
		memset(a, 0, sizeof a);

		cin >> n >> w >> l;

		for (int i = 0; i < w; i++) {
			cin >> x >> y;
			a[x][y] = 1;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				a[i][j] += (a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1]); 
		}

		int l = -1, r = n + 1;

		while (r - l > 1) {
			int mid = (l + r) >> 1;

			if (check(mid))
				l = mid;
			else
				r = mid;	
		}

		cout << l * l << endl;
	}

}