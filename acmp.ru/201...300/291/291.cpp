#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	int cnt[26] = {0};

	string s;

	vector <string> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	cin >> s;

	for (int i = 0; i < (int)s.length(); i++)
		cnt[s[i] - 'a']++;

	int ans = 0;

	for (int i = 0; i < n; i++)
		{
			int b[26] = {0};

			for (int j = 0; j < (int)a[i].size(); j++)
				b[a[i][j] - 'a']++;

			bool flag = true;

			for (int i = 0; i < 26; i++)
				flag &= (b[i] <= cnt[i]);

			ans += flag;
		}

	cout << ans;

	return 0;	
}
