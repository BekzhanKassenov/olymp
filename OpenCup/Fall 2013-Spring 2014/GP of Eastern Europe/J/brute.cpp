#include <iostream>
#include <cstdio>

using namespace std;

int get(int n) {
	if (n == 1 || n == 0) return 0;
	else if (n % 2 == 0)
		return 2 * get (n >> 1);
	else
		return 1 + get (n >> 1);
}

int main() {
	int ans = 0;

	for (int i = 1; i < 20; i++) {
		ans += get(i);
		
		cout << i << ' ' <<  ' ' << get(i) << ' ' << ans << endl;
	}

	return 0;
}
