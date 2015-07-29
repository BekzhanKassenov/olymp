#include <iostream>
#include <cstdio>

using namespace std;

int res = 0;

void gcd(int n, int m) {
	if (!n || !m) {
		return;
	}

	if (n < m)
		swap(n, m);

	res += n / m;
	n %= m;
	gcd(m, n);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;

	cin >> n >> m;

	gcd(n, m);

	cout << res;

	return 0;
}
