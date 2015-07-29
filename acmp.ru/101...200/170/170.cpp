#include <iostream>
#include <cstdio>

using namespace std;

void relax(int cnt, int sm, int& ans) {
	if (cnt - 1 <= sm && (sm - cnt + 1) % 2 == 0)
		ans = max(ans, cnt);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	n *= 2;

	int ans = 0;


	for (int i = 1; i * 1ll * i <= n; i++) {
		if (n % i == 0) {
			relax(i, n / i, ans);
			relax(n / i, i, ans);
		}
	}

	cout << ans;

	return 0;
}
