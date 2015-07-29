#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b) {
	return ((!a || !b) ? a + b : gcd(b % a, a));
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a, b;

	cin >> a >> b;

	cout << gcd(a, b);

	return 0;
}
