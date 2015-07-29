#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int nmb(char c)
{
	switch (c)
		{
			case 'N':
				return 0;

			case 'S':
				return 1;

			case 'W':
				return 2;

			case 'E':
				return 3;

			case 'U':
				return 4;

			case 'D':
				return 5;	
		}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;

	vector <vector <int> > a(6);

	for (int i = 0; i < 6; i++)
		{
			getline(cin, s);

			for (size_t j = 0; j < s.length(); j++)
				a[i].push_back(nmb(s[j]));
		}


	char c;

	int k;

	cin >> c >> k;

	vector <vector <int> > dp(6, vector <int> (k));

	for (int i = 0; i < 6; i++)
		dp[i][0] = 1;

	for (int len = 1; len < k; len++)
		{
			for (int i = 0; i < 6; i++)
				{
					for (size_t q = 0; q < a[i].size(); q++)
						dp[i][len] += dp[a[i][q]][len - 1];

					dp[i][len]++;
				}
		}

	cout << dp[nmb(c)][k - 1] << endl;	
}
