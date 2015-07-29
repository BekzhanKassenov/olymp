#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair

int d[4] = {1, 0, 0, -1};
int u[4] = {0, 1, -1, 0}; 

int n, k;

bool ok(int x, int y)
{
	if (x >= 0 && x < n)
		if (y >= 0 && y < n)	
			return true;

	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> k;

	vector <vector <int> > a(n, vector <int> (n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);

	vector <vector <int> > dp[2];

	dp[0].assign(n, vector <int> (n));
	dp[1].assign(n, vector <int> (n));

	dp[0][0][0] = a[0][0];

	int uk = 1;

	while (--k > 0)
		{
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					dp[uk][i][j] = 0;

			for (int x = 0; x < n; x++)
				for (int y = 0; y < n; y++)	
					{
					    if (dp[uk ^ 1][x][y] == 0)
					    	continue;
					
						for (int i = 0; i < 4; i++)
							{
								int cur_x = x + d[i];
								int cur_y = y + u[i];

								if (ok(cur_x, cur_y))
									{
										int tmp_cost = dp[uk ^ 1][x][y] + a[cur_x][cur_y];
                    				
                    					if (dp[uk][cur_x][cur_y] < tmp_cost)
											dp[uk][cur_x][cur_y] = tmp_cost;
									}
							}
				    }

			uk ^= 1;
       }

	int ans = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans = max(ans, dp[uk ^ 1][i][j]);

	cout << ans;

	return 0;
}
