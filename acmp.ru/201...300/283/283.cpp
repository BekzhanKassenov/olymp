#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s;
	cin >> s;
	int len = s.length();
	int i = 0;
	while (i < len)
		{
			if (! (s[i] >= 'A' && s[i] <= 'Z'))
				{
					cout << "No";
					return 0;
				}
			else
				{
					string str;
					str += s[i];
					i++;
					while (s[i] >= 'a' && s[i] <= 'z' && i < len)
						{	
							str += s[i];
							i++;
						}
					if (str.length() > 4 || str.length() < 2)
						{	
							cout << "No";
							return 0;
						}
				}
		}
	cout << "Yes";
	return 0;
}
