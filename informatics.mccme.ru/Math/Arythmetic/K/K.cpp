#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b) {
	return ((!a || !b) ? a + b : gcd(b % a, a));
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	int x, g = 0;

	for (int i = 0; i < n; i++) {
		cin >> x;
		g = gcd(g, x);
	}

	cout << g << endl;

	return 0;
}
