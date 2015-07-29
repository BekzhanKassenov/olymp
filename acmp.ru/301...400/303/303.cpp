#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int len;

int sum(string s)
{
	bool k = true;

	int ans = 0;

	for (int i = 0; i < len - 1; i++)
		{
			if (k)
				ans += s[i] - '0';

			else
				ans -= s[i] - '0';

			k ^= 1;
		}

	return ans;
}

int main()
{	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	string s;
	
	cin >> s;
	
	string tmp;

	int ans = -1000;

	len = s.length();

	for (int i = 0; i < len; i++)
		{
			tmp = s;
			tmp.erase(tmp.begin() + i);
			ans = max(ans, sum(tmp));
		}

	cout << ans;
	return 0;
}
