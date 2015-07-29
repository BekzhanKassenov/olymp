#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define int long long

main()
{
	vector <vector <int> > p(10);

	int n;
	cin >> n;

	p[0].push_back (4);
	p[0].push_back (6);
	p[1].push_back (6);
	p[1].push_back (8);
	p[2].push_back (7);
	p[2].push_back (9);
	p[3].push_back (4);
	p[3].push_back (8);
	p[4].push_back (0);
	p[4].push_back (3);
	p[4].push_back (9);
	p[6].push_back (0);
	p[6].push_back (1);
	p[6].push_back (7);
	p[7].push_back (2);
	p[7].push_back (6);
	p[8].push_back (1);
	p[8].push_back (3);
	p[9].push_back (2);
	p[9].push_back (4);


	if (n == 1)
		{
			cout << 8;
			return 0;
		}

	vector <vector <int> > dp(10, vector <int> (n + 1, 0));


	for (int i = 0; i < 10; i++)
		{
			if (i != 5)
				{
					dp[i][2] = (int)p[i].size();
				}
		}

	dp[4][2]--, dp[6][2]--;
	dp[1][2]--, dp[3][2]--;

	
	for (int i = 3; i <= n; i++)
		{
			for (int j = 0; j < 10; j++)
				{
					if (j != 5)
						{
							for (int k = 0; k < (int)p[j].size(); k++)
								dp[j][i] += dp[p[j][k]][i - 1];
						}
				}
		}

	int ans = 0;

	for (int i = 0; i < 10; i++)
		if (i != 5)
			ans += dp[i][n];


	cout << ans;
}
