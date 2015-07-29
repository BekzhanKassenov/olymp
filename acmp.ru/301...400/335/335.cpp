#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

#define MOD (1000 * 1000 * 1000 + 9)
#define make(a, b) (a * 10 + b)

int dp[10][10][10010];

vector <int> per[100];

bool prime(int n)
{
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;

	return (true);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	for (int i = 100; i <= 999; i++)
		{
			if (prime(i))
				{
					per[i / 10].push_back(i % 10);
					dp[(i % 100) / 10][i % 10][3]++;
				}
		}

	for (int len = 3; len <= n; len++)
		{
			for (int f = 0; f < 10; f++)
				for (int s = 0; s < 10; s++)
					{
						for (size_t i = 0; i < per[make(f, s)].size(); i++)
							{
								dp[s][per[make(f, s)][i]][len + 1] += dp[f][s][len];
								dp[s][per[make(f, s)][i]][len + 1] %= MOD;
							}
					}
		}

 	int ans = 0;

 	for (int i = 0; i < 10; i++)
 		for (int j = 0; j < 10; j++)
 			ans = (ans + dp[i][j][n]) % MOD;

 	cout << ans;
}
                         