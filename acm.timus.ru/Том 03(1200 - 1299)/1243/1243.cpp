#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	string s;

	cin >> s;

	int ans = 0;

	for (int i = 0; i < (int)s.length(); i++)
		{
			ans *= 10;

			ans += s[i] - '0';

			ans %= 7;
		}

	cout << ans;
	return 0;
}