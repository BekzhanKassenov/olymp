#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

bool is_ok(int n) {
	if (n == 0)
		return false;

	while (n) {
		if ((n % 10 != 1) && (n % 10 != 2))
			return false;

		n /= 10;
	}

	return true;
}

int ans[100010];

int main() {
	freopen("in", "r", stdin);

	for (int i = 0; i < 100000; i++)
		ans[i] = 1000000;

	for (int i = 0; i < 100000; i++) {
	 	if (is_ok(i)) {
	 		int c = i;

	 		for (int j = 2; j * j <= c; j++) {
	 			if (c % j == 0) {
	 				ans[j] = min(ans[j], c);

	 				ans[c / j] = min(ans[c / j], c);
	 			}
	 		}
	 	}
	}

	for (int i = 0; i < 15; i++)
		cout << i << ' ' << ans[i] << endl;
}
