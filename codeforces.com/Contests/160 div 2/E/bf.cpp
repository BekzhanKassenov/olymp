#include <iostream>
#include <cstdio>

using namespace std;

int a[200][200];

int main()
{
	//freopen("out", "w", stdout);

	int m;

	cin >> m;

	for (int j = 1; j <= m; j++)
		a[1][j] = 0;

	a[1][m + 1] = 1;

	for (int i = 2; i <= (m + 1); i++)
		{
			for (int j = 1; j <= 2 * (m + 1); j++)
				{
					if (j == 1)
						{
							a[i][j] = a[i - 1][j + 1];
						}
					else
						{
							if (j == 2 * (m + 1))
								a[i][j] = a[i - 1][j - 1];
							else
								a[i][j] = a[i - 1][j - 1] ^ a[i - 1][j + 1];
						}	
				}
		}

	for (int i = 1; i <= m + 1; i ++)
		{
			for (int j = 1; j <= 2 * (m + 1); j++)
				{
					if (a[i][j])
						cout << a[i][j] << ' ';
					else
						cout << "  ";
				}	

			cout << endl;
		}

	for (int i = 1; i <= m + 1; i ++)
		{
			int ans = 0;
			for (int j = 1; j <= 2 * (m + 1); j++)
				{
					ans += a[i][j];
				}	

			cout << ans << ' ';
		}

}
