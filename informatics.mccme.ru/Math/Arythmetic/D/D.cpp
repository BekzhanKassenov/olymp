#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int res[4];
int sz = 0;

bool solve(int n, int gl) {
	if (gl > 4 || n < 0)
		return false;

	int k = sqrt(n);

	if (k * k == n) {
		res[sz++] = k;
		return true;
	}

	for (int i = 1; i <= k; i++) {
		if (solve(n - i * i, gl + 1)) {
			res[sz++] = i;
			return true;
		}
	}

	return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	solve(n, 1);

	for (int i = 0; i < sz; i++)
		cout << res[i] << " \n"[i == sz - 1];

	return 0;
}
