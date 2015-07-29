#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n;

	cin >> n;

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector <int> dp(n, 0);

	vector <int> pr(n, -1);

	dp[0] = 1;

	int ans = 0;

	for (int i = 1; i < n; i++)
		{
			dp[i] = 1;

			for (int j = 0; j < i; j++)
				if (a[i] > a[j] && dp[i] < dp[j] + 1)
					{
						dp[i] = dp[j] + 1;
						pr[i] = j;
					}
			if (dp[ans] < dp[i])
				ans = i;
		}

	cout << dp[ans] << endl;

	vector <int> an;

	an.reserve(dp[ans]);

	for (int i = ans; i != -1; i = pr[i])
		an.push_back(a[i]);

	for (int i = dp[ans] - 1; i >= 0; i--)
		cout << an[i] << ' ';

	return 0;
}
