#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s;
	
	cin >> s;

	string ans;

	ans += (s[0] - 'a' - 5 + 26) % 26 + 'a';

	for (int i = 1; i < (int)s.length(); i++)
		{
			ans += ((s[i] - s[i - 1] + 26) % 26 + 'a');
		}

	cout << ans;	
}
