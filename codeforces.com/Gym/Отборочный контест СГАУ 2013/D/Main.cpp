#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int cnt[200010][26];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	int n;
	cin >> n;
	string s;

	for (int j = 0; j < 3; j++) {
		cin >> s;
		for (int i = 0; i < n; i++)
			cnt[i][s[i] - 'a']++;
	}

	for (int i = 0; i < n; i++) {
		int ans = 0;
		for (int j = 1; j < 26; j++)
			if (cnt[i][j] > cnt[i][ans])
				ans = j;

		cout << char(ans + 'a');
	}
	cout << endl;

	return 0;
}