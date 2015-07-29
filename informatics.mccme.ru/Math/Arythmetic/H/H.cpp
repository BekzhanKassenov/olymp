#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			puts("composite");
			return 0;
		}
	}

	puts(n <= 1 ? "composite" : "prime");

	return 0;
}
