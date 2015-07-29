#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s;

	cin >> s;

	int a[26] = {0};

	for (int i = 0; i < (int) s.length(); i++)
		a[s[i] - 'a']++;

	int ans = 0;

	char c;

	for (int i = 0; i < 26; i++)
		if (a[i] > ans)
			{
				ans = a[i];
				c = i + 'a';
			}

	cout << c;

	return 0;
}
