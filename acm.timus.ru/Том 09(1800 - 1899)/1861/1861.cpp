#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

bool comp(char a, char b) {
	if (a == '?' || b == '?')
		return true;

	return (a == b);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
   	#endif

   	string s, t;

   	getline(cin, s);
   	getline(cin, t);

   	int len = t.size();

   	int ans = 0;

   	for (size_t i = 0; i <= s.size() - t.size(); i++) {
   		bool flag = true;

		for (int j = 0; j < len && flag; j++) {
			flag = comp(s[i + j], t[j]); 	
		}	

		ans += flag;
   	}

   	cout << ans;

   	return 0;
}
