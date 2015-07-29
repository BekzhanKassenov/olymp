#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	vector <vector <int> > dp(10, vector <int> (81));

	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;

	if (n == 1)
		{
			cout << 10;
			return 0;
		}

	if (n == 81)
		{
			cout << 1;
			return 0;
		}	

	for (int i = 1; i < 9; i++)  //dlina
		{
			for (int j = 0; j <= 9; j++)  //cifra
				{
					for (int k = 0; k <= 81; k++) //summa
						if (k - j >= 0)
							dp[i + 1][k] += dp[i][k - j];
				}
		}

	/*for (int i = 1; i <= 9; i++)
		{
			for (int j = 0; j <= 81; j++)
				cout << dp[i][j] << ' ' ;
			cout << endl;	
		}  */
	cout << dp[9][n] << endl;
}
