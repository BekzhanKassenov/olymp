#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	string s, t;

	map <string, int> m;

	for (int i = 0; i < (1 << n); i++) {
		cin >> s >> t;

		m[t]++;
	}

	int cnt = 0;

	for (map <string, int> :: iterator it = m.begin(); it != m.end(); it++) 
		cnt = max(cnt, it -> second);
		
	int ans = 0;

	while (cnt <= (1 << (n - 1))) {
		ans++;
		n--;
	}

	cout << ans;

	return 0;
}
