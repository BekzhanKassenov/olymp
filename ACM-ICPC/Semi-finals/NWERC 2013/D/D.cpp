#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;

int k, l[10], a[10][10], end[10][10], n, ans;

bool ok(int a, int b) {
	return (a >= 0 && b >= 0);
}

void rec(int i, int j) {
	if (j == l[i]) {
		j = 0, i++;
	}

	if (i == k) {
		ans++;
		return;
	}

	int st = 1;

	if (ok(i - 1, j))
		st = max(st, a[i - 1][j] + 1);

	if (ok(i, j - 1))
		st = max(st, a[i][j - 1]);

	for (int q = st; q <= end[i][j]; q++) {
		a[i][j] = q;

		rec(i, j + 1);
	}
}

int main() {
	#ifdef Local
		freopen("in", "r", stdin);
	#endif

	stringstream ss;

	double start = clock();

	while (scanf("%d", &k) == 1) {
		for (int i = 0; i < k; i++)
			scanf("%d", &l[i]);

		scanf("%d", &n);
		memset(end, 0, sizeof end);
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < l[i]; j++) {
				for (int t = i + 1; t < k; t++)
					if (l[t] > j)
						end[i][j]++;
			}
		}

		for (int i = 0; i < k; i++)
			for (int j = 0; j < l[i]; j++)
				end[i][j] = n - end[i][j];
		
		ans = 0;
		rec(0, 0);
		
		ss << ans << endl;
	}

	cout << ss.str();

	#ifdef Local
		cout << (clock() - start) / CLOCKS_PER_SEC << endl;
	#endif

	return 0;
}
