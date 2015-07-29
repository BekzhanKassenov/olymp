#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool prime(int n)
{
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;

 	return true;
}

int make(int a, int b)
{
	return (a * 10 + b);
}

vector <int> go[100];

int dp[10][10][10010];

const int MOD = 1000 * 1000 * 1000 + 9;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	for (int i = 100; i < 999; i++)
		{
			if (prime(i))
				{
					go[i / 10].push_back(i % 10);
					dp[(i / 10) % 10][i % 10][3]++;
				}
		}

	for (int len = 3; len < n; len++)
		{
			for (int a = 0; a < 10; a++)
				for (int b = 0; b < 10; b++)
					{
						int first = make(a, b);

						for (size_t i = 0; i < go[first].size(); i++)
							{
								dp[b][go[first][i]][len + 1] += dp[a][b][len];
								dp[b][go[first][i]][len + 1] %= MOD;
							}
					}
		}	

	int ans = 0;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			{
				ans += dp[i][j][n];
				ans %= MOD;
			}

   	cout << ans;
}
