#include <iostream>
#include <cstdio>

using namespace std;

long long solve(long long n, int len) {
	if (len == 0)
		return 0;

	if (n > (1ll << (len - 1)))
		return (1 + solve(n - (1ll << (len - 1)), len - 1));

	return solve(n, len - 1);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int q;
	long long n, p;

	cin >> q;

	while (q--) {
		cin >> n >> p;

		int len = 0;

		while ((1ll << len) < n)
			len++;

		cout << solve(n, len) % p << endl;
	}

	return 0;
}
