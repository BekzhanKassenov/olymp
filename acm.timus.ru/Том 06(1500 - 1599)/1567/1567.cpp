#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int cnt(char a)
{
	if (a == '.')
		return 1;

	if (a == ',')
		return 2;

	if (a == '!')
		return 3;

	if (a == ' ')
		return 1;

	return ((a - 'a') % 3 + 1);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s;

	getline(cin, s);

	int ans = 0;

	for (int i = 0; i < (int) s.length(); i++)
		ans += cnt(s[i]);

	cout << ans;
}
