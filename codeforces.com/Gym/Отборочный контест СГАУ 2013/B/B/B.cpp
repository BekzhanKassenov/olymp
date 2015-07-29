#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

string remake(const string& s) {
	int cnt[26];
	for (int i = 0; i < 26; i++)
		cnt[i] = -1;

	int cn = 0;
	string ans(s.begin(), s.end());

	for (size_t i = 0; i < s.size(); i++) {
		if (cnt[s[i] - 'a'] == -1)
			cnt[s[i] - 'a'] = cn++;
		
		ans[i] = cnt[s[i] - 'a'] + 'a';
	}
	return ans;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	
	int n;
	cin >> n;
	string s;
	map <string, int> Map;
	for (int i = 0; i < n; i++) {
		cin >> s;
		Map[remake(s)]++;
	}

	long long ans = 0;
	for (map <string, int> :: iterator it = Map.begin(); it != Map.end(); it++)
			ans += ((it -> second) * 1ll * (it -> second - 1)) >> 1ll;
	cout << ans;
}