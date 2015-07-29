#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <vector <long long> > dp;

long long solve(int n, int j)
{
	long long ans = 0;

	if (n == 0)
		return 1;

	if (dp[n][j] != -1)
		return dp[n][j];
	
	for (int i = j + 1; i <= n; i++)
		if (n - i >= 0)
			ans += solve(n - i, i);

	return (dp[n][j] = ans);
}

int main()
{
	int n;
	cin >> n;

	dp.assign(n + 1, vector <long long> (n + 1, -1));

	cout << solve(n, 0) - 1;
}
