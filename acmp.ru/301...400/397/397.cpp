#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;

	cin >> s;

	char mx = 'a', mn = 'z';

	for (int i = 0; i < (int)s.length(); i++)
		{
			mx = max(mx, s[i]);
			mn = min(mn, s[i]);
		}

	vector <int> pos;

	for (int i = 0; i < (int)s.length(); i++)
		{
			if (s[i] == mx || s[i] == mn)
				pos.push_back(i);
		}

	int ans = 1000000000, l = -1;

	for (int i = 0; i < (int) pos.size() - 1; i++)
		{
			if (s[pos[i]] != s[pos[i + 1]])
				{
					if (pos[i + 1] - pos[i] < ans)
						{
							l = pos[i];
							ans = pos[i + 1] - pos[i];
						}
				}
		}

	if (l != -1)	
		cout << s.substr(l, ans + 1);
	else
		cout << s[0];

	return 0;
}
