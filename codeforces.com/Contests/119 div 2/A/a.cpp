#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

#define INF -1

int main()
{
   #ifndef ONLINE_JUDGE
   	freopen("in", "r", stdin);
   #endif

   int n, a, b, c;
   
   cin >> n >> a >> b >> c;
	
	vector <int> dp(n + 1, INF);

	if (a <= n)
		dp[a] = 1;

	if (b <= n)
		dp[b] = 1;

	if (c <= n)
		dp[c] = 1;

	for (int i = 0; i < n; i++)
		{
			if (dp[i] > INF)
				{
					if (i + a <= n)
						dp[i + a] = max(dp[i + a], dp[i] + 1);

					if (i + b <= n)
						dp[i + b] = max(dp[i + b], dp[i] + 1);

					if (i + c <= n)
						dp[i + c] = max(dp[i + c], dp[i] + 1);
				}
		}
 	cout << dp[n];
	return 0;
}
