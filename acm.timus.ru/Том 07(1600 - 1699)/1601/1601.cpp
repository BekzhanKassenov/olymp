#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	bool flag = true;
	
	string s;
	
	while (getline(cin, s))
		{
			for (int i = 0; i < (int)s.size(); i++)
				{
					if (s[i] == '.' || s[i] == '!' || s[i] == '?')
						flag = true;

					if (s[i] >= 'A' && s[i] <= 'Z')
						{
							if (flag)
								{
									flag = false;
									continue;
								}
							else
								s[i] = tolower(s[i]);	
						}
				}

			cout << s << endl;	
		}

  	return 0;
}
