#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;

	cin >> s;

	int n = s.length();

	if ((n & 1) || s[0] == ')' || s[n - 1] == '(')
		{
			cout << 0;
			return 0;
		}

	vector <vector <int> > dp(n + 1, vector <int> (n + 1));

	for (int i = 0; i <= n; i++)
		dp[i][i] = 1;

	for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
				{
					if (j == 0)
						{
							if (s[i - 1] == ')' || s[i - 1] == '?')
								dp[i][j] = dp[i - 1][j + 1]; 
							continue;
						}
					if (s[i - 1] == '?')
						{
							dp[i][j] = dp[i - 1][j + 1] + dp[i - 1][j - 1];
						}

					if (s[i - 1] == '(')
						{
							dp[i][j] = dp[i - 1][j - 1];
						}

					if (s[i - 1] == ')')
						dp[i][j] = dp[i - 1][j + 1];	
				}
		}

	cout << dp[n][0];

	return 0;
}
