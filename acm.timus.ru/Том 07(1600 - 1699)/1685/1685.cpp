#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

void make(vector <int>& ans, int l, int r) {
	if (l > r)
		return;

	int m = (l + r) >> 1;

	ans.push_back(m);
	make(ans, l, m - 1);
	make(ans, m + 1, r);
}   

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s;

	getline(cin, s);

	vector <int> a;

	make(a, 0, s.size() - 1);

	string ans;

	for (int i = 0; i < (int)s.size(); i++)
		ans += ' ';

	for (int i = 0; i < (int)s.size(); i++)
		ans[a[i]] = s[i];

	cout << ans;	

	cout << endl;
	
	return 0;
}
