#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	
	cin >> n;

	int ans = (n / 107) * 100;
	n %= 107;
	int res = (ans / 100) * 7;

	if (n > 7) {
		ans += n - 7;
		res += 7;
	}

	cout << ans << ' ' << res;

	return 0;	
}
