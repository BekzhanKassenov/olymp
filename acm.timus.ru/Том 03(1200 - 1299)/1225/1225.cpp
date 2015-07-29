#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define ll long long

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	ll n;

	cin >> n;

	vector <ll> dp(max(n + 1, 4 * 1ll));

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;

	for (int i = 4; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}

	cout << 2 * dp[n];

	return 0;
}
