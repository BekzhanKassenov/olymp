#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

bool test(char c)
{
	if ((c<='9' && c>='0') || (c>='A' && c<='Z'))
		return true;
	return false;
}

int base(char c)
{
	if (c<='9' && c>='0')
		return (c-'0'+1);
	else
		return (c-'A'+11);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s;
	getline(cin,s);
	int ans=2;
	for (int i=0;i<s.length();i++)
		{
			if (test(s[i]))
				ans = max(ans, base(s[i]));
			else
				{
					cout << -1;
					return 0;
				}
		}
	cout << ans;
	return 0;
}
