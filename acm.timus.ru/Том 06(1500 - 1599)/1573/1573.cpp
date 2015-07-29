#include <iostream>
#include <cstdio>
#include <string>
#include <cassert>

using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int ans = 1;

	int k;

	int b, r, y;

	cin >> b >> r >> y;

	string s;

	cin >> k;

	assert(k <= 3);

	for (int i = 0; i < k; i++) {
		cin >> s;

		if (s == "Blue")
			ans *= b;

		if (s == "Red")
			ans *= r;

		if (s == "Yellow")
			ans *= y;	
	}

	cout << ans;
	return 0;	
}
