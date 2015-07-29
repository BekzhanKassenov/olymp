#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s;
	cin >> s;
	int len = s.length();
	map <string, int> m;
	int ans = 0;
	for (int i = 0; i < len; i++)
		{
			for (int j = 1; i + j <= len; j++)
				{
					string k = s.substr(i, j);
					sort(k.begin(), k.end());
					m[k] ++;
					if (m[k] > 1)
						ans = max(ans, j);
				}
		}
	cout << ans;
	return 0;
}
