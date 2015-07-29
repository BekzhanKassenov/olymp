#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <vector <int> > can;

int n, m;

bool check(int p1, int p2)
{
	for (int i = 1; i < n; i++)
		{
			int a = ((p1 & (1 << i)) > 0);
			int b = ((p1 & (1 << (i - 1))) > 0);

			int c = ((p2 & (1 << i)) > 0);
			int d = ((p2 & (1 << (i - 1))) > 0);

			if (a > 0 && b > 0 && c > 0 && d > 0)
				return false;

			if (a == 0 && b == 0 && c == 0 && d == 0)
				return false;
		}

	return true;
}

void build()
{
	for (int i = 0; i < (1 << n); i++)
		{
			for (int j = 0; j < (1 << n); j++)
				{
					if (check(i, j))
						{
							can[i][j] = 1;
							can[j][i] = 1;
						}
				}
		}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> m;

	if (n > m)
		swap(n, m);

	can.assign(1 << n, vector <int> (1 << n));

	build();

	vector <vector <int> > dp(m + 1, vector <int> (1 << n));

	dp[0][0] = 1;

	for (int i = 0; i < (1 << n); i++)
		{
			dp[0][i] = 1;
		}

	for (int j = 1; j <= m; j++)
		{
			for (int i = 0; i < (1 << n); i++)
				{
					for (int k = 0; k < (1 << n); k++)
						{
							dp[j][i] += dp[j - 1][k] * can[i][k];
						}
				}
		}

	int ans = 0;

	for (int i = 0; i < (1 << n); i++)
		ans += dp[m - 1][i];
	
	cout << ans;
}
