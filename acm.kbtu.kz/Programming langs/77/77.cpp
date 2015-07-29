#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int cnt[27];

int main()
{
	string s;
	while (cin >> s)
		{
			for (int i = 0; i < (int) s.length(); i++)
				{
					if (s[i] >= 'A' && s[i] <= 'Z')
						cnt[s[i] - 'A'] ++;
					if (s[i] >= 'a' && s[i] <= 'z')
						cnt[s[i] - 'a'] ++;	
				}
		}
	for (int i = 0; i < 26; i++)
		cout << char(i + 'A') << " - " << cnt[i] << endl;
	return 0;
}

