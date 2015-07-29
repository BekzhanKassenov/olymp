#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

bool palindrom(string s)
{
	int len = s.length();
   for (int i = 0; i <= len / 2; i++)
   	if (s[i] != s[len - i - 1])
   return false;
   return true;
}

string mx(string a, string b)
{
	if (a > b)
		return a;
	return b;
}

int main()
{
	string s;
	cin >> s;
	int len = s.length();
	string ans;
	for (int mask = 1; mask < (1 << len); mask++)
		{
			string z;
			for (int j = 0; j < len; j++)
				if ((mask & ( 1 << j )) > 0)
					z+=s[j];
			if (palindrom(z))
				ans = mx(ans,z);
		}
	cout << ans;
	return 0;
}
