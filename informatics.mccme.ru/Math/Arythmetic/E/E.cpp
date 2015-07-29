#include <iostream>
#include <cstdio>

using namespace std;

int used[1000000];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	for (int i = 0; i * i * i <= n; i++) {
		used[i * i * i] = i;
		if (i * i * i == n) {
			cout << i << ' ' << 0;
			return 0;
		}
    }

	for (int i = 1; i * i * i <= n; i++) {
		if (used[n - i * i * i]) {
		 	cout << i << ' ' << used[n - i * i * i];
			return 0;
		}
	}

	cout << "impossible";

	return 0;
}
