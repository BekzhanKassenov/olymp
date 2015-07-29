#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	
	int ans = 0, cnt = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == t[i]) {
			ans += (cnt != 0);
			cnt = 0;
		} else
			cnt++;
	}
	ans += (cnt != 0);
	cout << ans;

	//while (true) {}

	return 0;
}