#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map <int, int> mem;

int solve(int n) {
	if (n == 1)
		return 1;
	if (n == 2 || n == 3)
		return 2;
	if (n == 4 || n == 5)
		return 3;

	if (mem.count(n))
		return mem[n];

	int ans = (n >> 1) + 1;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			int nmb = i, amount = n / i;
			ans = min(ans, solve(nmb) * ((amount >> 1) + 1));
			if (i * i != n) {
				int nmb = n / i, amount = i;
				ans = min(ans, solve(nmb) * ((amount >> 1) + 1));
			}
		}
	}

	mem[n] = ans;
	return ans;
}

int main() {
	int n;

	cin >> n;

	cout << solve(n);
	return 0;
}