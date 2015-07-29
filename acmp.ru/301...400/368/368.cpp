#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define F first
#define S second

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;
	
	vector <vector <int> > a(n, vector <int> (n));

	char c;

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				{
					cin >> c;
					a[i][j] = c - '0';
				}
		}

	vector <vector <int> > dp(n, vector <int> (n));

	dp[0][0] = a[0][0];

	for (int i = 1; i < n; i++)
		{
			dp[0][i] = dp[0][i - 1] + a[0][i];
			dp[i][0] = dp[i - 1][0] + a[i][0];
		}
	for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < n; j++)
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
		}	


	vector <vector <int> > way(n, vector <int> (n));

	pair <int, int> now = make_pair(n - 1, n - 1);

	for (;;)
		{
			way[now.F][now.S] = true;

			//cout << now.F + 1 << ' ' << now.S + 1 << endl;

			if (now == make_pair(0, 0))
				break;

			if (now.F > 0 && dp[now.F][now.S] - a[now.F][now.S] == dp[now.F - 1][now.S])
				now.F--;
			else
				now.S--;
		}

	for (int i = 0; i < n; i++)	
		{
			for (int j = 0; j < n; j++)
				if (way[i][j])
					cout << '#';
				else
					cout << '.';

			cout << endl;
		}

	return 0;
}
