#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

string name = "Sandro";

bool type(char c)
{
	if (c >= 'a' && c <= 'z')
		return false;

	return true;
}

int cost(const string& s)
{
	int ans = 0;

	for (int i = 0; i < 6; i++)
		{
			if (s[i] != name[i])
				{
					if (tolower(s[i]) == tolower(name[i]) || (type(s[i]) == type(name[i])))
						ans += 5;
					else
						ans += 10;	
				}
		}

	return ans;	
}

int main()
{
	string s;
	
	cin >> s;

	int len = s.length();

	int ans = 1000000;

	for (int i = 0; i <= len - 6; i++)
	 	{
	 		string tmp = s.substr(i, 6);

	 		ans = min(ans, cost(tmp));
	 	}

	cout << ans;
 
}

