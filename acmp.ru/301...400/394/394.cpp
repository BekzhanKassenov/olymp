#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int gcd(int a, int b) {
	if (a == 0 || b == 0)
		return a + b;

	return gcd(b, a % b);	
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;

	cin >> n >> m;

	cout << n / gcd(n, m);
}
