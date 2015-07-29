#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string s;

int str_to_int(string s)
{
	int ans = 0;
	for (int i = 0; i < s.length(); i++)
		{
			ans *= 10;
			ans += s[i] - '0';
		}
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> s;
	string ans;
	int len = s.length();
	int i = 0;
	char a;
	while (i < s.length())
		{
			if (s[i] >= '0' && s[i] <= '9')
				{	
					string nmb;
					while (s[i] >= '0' && s[i] <= '9' && i < len)
						{
							nmb += s[i];
							i++;
						}
					int k = str_to_int(nmb);
					a = s[i];
					i++;
					for (int j = 0; j < k; j++)
						ans += a;
				}
			else
				{
					ans += s[i];
					i++;
				}
		}
  	i = 0;
  	len = ans.length();
 	while (i < len)
  		{
  			int f = i + 40;
  			for (; i < min(f, len); i++)
  				cout << ans[i];
  			cout << endl;
  		}
  	return 0;
}
