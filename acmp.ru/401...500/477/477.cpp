#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;

	cin >> s;

	int ans = 0;

	for (size_t i = 0; i < s.length(); i++)
		{
			ans = (ans * 10 + s[i] - '0') % 3;
		}

	if (ans == 0)
		cout << 2;
	else
		cout << 1 << endl << ans;

	return 0;	
}
