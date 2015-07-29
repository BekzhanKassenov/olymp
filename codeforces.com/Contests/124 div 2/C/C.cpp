#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	char a = 'z';
	int k = 0;
	int len = s.length();
	string ans;
	while (k<len-1 || a>='a')
		{
			for (int i=k;i<len;i++)
				if (s[i]==a)
					{
						ans += s[i];
						k = i;
					}
			a--;
		}
	cout << ans;
	return 0;
}
