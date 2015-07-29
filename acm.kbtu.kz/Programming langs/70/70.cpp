#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	string ans;
	int i = 0;
	while (i < (int)s.length())
		{
			if (s[i] == ' ')
				{
					while (s[i] == ' ' && i < (int)s.length())
						i++;
					ans += ' ';
				}
			else
				{	
					ans += s[i];
					i++;
				}	
		}
	cout << ans;
	return 0;
}
