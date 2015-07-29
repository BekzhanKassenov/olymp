#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

bool lucky(string& s)
{
	if (!s.empty())
		for (int i = 0; i < s.length(); i++)
			if (s[i] == '4' || s[i] == '7')
				continue;
			else
				return false;
	else
		return false;
	return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s;
	cin >> s;

	map <string, int> m;

	int len = s.length();

	int ans = 0;

	string kl;
	for (int i = 0; i < len; i++)
		{
			for (int j = 1; j + i <= len; j++)
				{
					string k = s.substr(i, j);
					//cout << k << ' ' << lucky(k) << endl;
					if (lucky(k))
						{
							int z = ++m[k];
							if (z > ans)
								{
									ans = z;
									kl = k;
								}
							if (z == ans)
								if (k < kl)
									kl = k;
						}
				}
		}
	cout << ((kl.empty()) ? ("-1") : (kl));
	return 0;	
}
