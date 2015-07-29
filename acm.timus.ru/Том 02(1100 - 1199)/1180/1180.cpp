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

	int ans = 0;

	for (int i = 0; i < (int)s.length(); i++)
		{
			ans = (ans * 10 + s[i] - '0') % 3;
		}

	if (ans == 0)
		{
			cout << 2;
			return 0;
		}

	cout << 1 << endl << ans;

	return 0;
}
