#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int k;

	cin >> k;

	const int INF = (int)2e9;

	vector <int> dp(k + 1, INF);

	dp[0] = 0;

	for (int i = 1; i <= k; i++)
		{
			for (int j = 0; j < n; j++)
				{
					if (i - a[j] >= 0)
						dp[i] = min(dp[i], dp[i - a[j]] + 1);
				}
		}


	if (dp[k] < INF)
		cout << dp[k];
	else
		cout << -1;

	return 0;	
}
