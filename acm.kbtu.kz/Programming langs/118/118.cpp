#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 2000000000

int main()
{
	int n;
	cin >> n;

	vector <vector <int> > g(n, vector <int> (n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> g[i][j];

	vector <vector <int> > dp((1 << n) , vector <int> (n, INF));

	vector <vector <int> > pr((1 << n) , vector <int> (n, -1));

	for (int i = 0; i < (1 << n); i++)
		dp[i][0] = 0;

	for (int mask = 0; mask < (1 << n); mask ++)
		{
			for (int i = 0; i < n; i++)
				{
					if (((mask & (1 << i)) > 0) && (dp[mask][i] < INF))
						for (int j = 0; j < n; j++)
							{
								if ((mask & (1 << j)) == 0 && dp[mask + (1 << j)][j] > dp[mask][i] + g[i][j])
									{
										dp[mask + (1 << j)][j] = dp[mask][i] + g[i][j];
										pr[mask + (1 << j)][j] = i;
									}
							}
				}
		}

	int l = ((1 << n) - 1);

	int ans = 0;

	for (int i = 0; i < n; i++)
		{
			if (dp[l][i] < dp[ans][i])
				ans = i;
		}

	cout << dp[l][ans] << endl;

	int k = ans;

	vector <int> p;

	p.push_back(ans);

	while (l != 0)
		{
			if (pr[l][k] != -1)
				p.push_back(pr[l][k]);
			
			int tmp = pr[l][k];

			l -= (1 << k);
			
			k = tmp;
		}  

	for (int i = 0; i < (int)p.size(); i++)
		cout << p[i] + 1 << ' ';
}
