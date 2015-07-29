#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

string s;

int n;

bool check(char c1, char c2)
{
	if (c1 == '(' && c2 == ')')
		return true;
   if (c1 == '{' && c2 == '}')
   	return true;
   if (c1 == '[' && c2 == ']')
   	return true;
   return false;
}

vector <vector <int> > dp;

void solve(int l, int r)
{
	if (dp[l][r] != -1)
		return;

	if (l > r)
		{
			dp[l][r] = 0;
			return;
		}
	if (l == r)
		{
			dp[l][r] = 1;
			return;
		}

	if (r - l == 1)
		{
			if (check(s[l], s[r]))
				dp[l][r] = 0;
			else
				dp[l][r] = 2;
			return;
		}
	if (check(s[l], s[r]))
		{
			solve(l + 1, r - 1);

			dp[l][r] = dp[l + 1][r - 1];
		}
	else
		dp[l][r] = 100000;

	for (int i = l; i < r; i++)
		{
			solve(l, i);
			solve(i + 1, r);

			dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r]);
		}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> s;

	if (s.empty())
		{
			cout << 0;
			return 0;
		}
	
	n = s.length();

	dp.resize(n, vector <int> (n, -1));

	solve(0, n - 1);

	cout << dp[0][n - 1] << endl;

	return 0;
}

