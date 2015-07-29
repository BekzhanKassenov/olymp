#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;

	cin >> n >> m;

	vector <vector <int> > a(n + 1, vector <int> (m + 1, -1));

	a[1][1] = 0;

	for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				{
					if (a[i][j] == -1)
						{
							int x = i;

							int ans = -1;

							do	
								{
									
									x--;
									
									if (a[x][j] == 0)
										ans = 1;
								}
							while (x > 1);

							x = j;

							do
								{
									x--;

									if (a[i][x] == 0)
										ans = 1;
								}
							while (x > 1);
							
							x = i;

							int y = j;

							do
								{
									x--, y--;

									if (a[x][y] == 0)
										ans = 1;
								}
							while (x > 1 && y > 1);
							
							a[i][j] = (ans == -1) ? (0) : (1);
						}
				}
		}

  	if (a[n][m])
  		cout << 1;
  	else
  		cout << 2;

  	return 0;	
}
