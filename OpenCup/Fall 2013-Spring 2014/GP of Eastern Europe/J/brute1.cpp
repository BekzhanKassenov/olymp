#include <iostream>
#include <cstdio>

using namespace std;

int f(int n) {
	int ans = 0, cur = 1;

	while (n > 1) {
		ans += (cur * (n & 1));
		cur <<= 1;
		n >>= 1;
	}

	return ans;
}

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int n;
	cin >> n;

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		ans += f(i);
	}

	cout << ans;
}    
