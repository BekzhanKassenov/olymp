#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			cout << i << ' ';
			n /= i;
		}
	}

	if (n > 1)
		cout << n << endl;

	return 0;
}
