#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	char s[100];

	scanf("%s", s);

	freopen(s, "r", stdin);

	string t;

	int ans = 0;

	while (cin >> t)
		{
			ans += t.length();
		}
	cout << ans;
}