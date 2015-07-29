#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define INF 1000000

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	vector <int> dp(n + 1, INF);

	dp[0] = dp[1] = 1;

	for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j * j <= i; j++)
				{
					if (j * j == i)
						{
							dp[i] = 1;
							break;
						}
					dp[i] = min(dp[i], dp[i - j * j] + 1);
				}
		}

	cout << dp[n];

	return 0;
}

