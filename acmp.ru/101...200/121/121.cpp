#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

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

	sort(a.begin(), a.end());

	vector <int> dp(n, 0);

	dp[0] = 2000000000;

	dp[1] = a[1] - a[0];

	for (int i = 2; i < n; i++)  	
		dp[i] = min(dp[i - 1], dp[i - 2]) + (a[i] - a[i - 1]);

	cout << dp[n - 1];
	return 0;
	
}
