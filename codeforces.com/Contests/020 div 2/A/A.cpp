#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s;

	cin >> s;

	string ans;

	int pos = 0;

	int len = s.length();

	while (pos < len)
		{
			if (s[pos] == '/')
				{
					ans += '/';

					while (s[pos] == '/')
						pos++;
				}
			else
				ans += s[pos++];	
		}

  	if (ans[ans.size() - 1] == '/')
  		ans.erase(ans.end() - 1);
	
	if (ans.empty())
		cout << '/';
	else	
		cout << ans;

	return 0;	
}
