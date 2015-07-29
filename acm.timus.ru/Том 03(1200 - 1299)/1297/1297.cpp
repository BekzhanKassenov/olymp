#include <string>
#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

string s;

vector <vector <int> > dp;

int len;

int clc(int l, int r)
{
	if (l == r)
		return 1;

	if (dp[l][r] != -1)
		return dp[l][r];

	if (l > r)
		return 0;

	if (s[l] == s[r])
		{
			if (r - l == 1 || r - l == 2)
				{
					return (dp[l][r] = (r - l + 1));
				}
			else
				if (clc(l + 1,r - 1) == (r - 1 - (l + 1) + 1))
					return (dp[l][r] = clc(l + 1, r - 1) + 2);
		}

	dp[l][r] = max(clc(l + 1, r), clc(l, r - 1));
	
	//cout << l << ' ' << r << ' ' << dp[l][r] << endl;

	return dp[l][r];
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> s;

	len = s.length();

	if (len == 1)
		{
			cout << s;
			return 0;
		}

	dp.assign(len, vector <int> (len, -1));

	clc(0, len - 1);

	if (dp[0][len - 1] == 1)
		{
			cout << s[0];
			return 0;
		}

	for (int i = 0; i < len; i++)
		{
			int j = i + dp[0][len - 1] - 1;
			if (dp[i][j] == dp[0][len - 1])
				{
					cout << s.substr(i, dp[0][len - 1]) << endl;
					return 0;
				}
		}

	//cout << dp[0][len - 1] << endl;
	return 0;
}
