#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("cities.in", "r", stdin);
	freopen("cities.out", "w", stdout);

	int n;

	cin >> n;

	char c;

	vector <vector <int> > a(n, vector <int> (n));

	int cnt = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			{
				cin >> c;

				if (c == 'C')
					{
						a[i][j] = 1;
						cnt++;
					}
				else
					a[i][j] = 0;
			}

  	cnt >>= 1;

  	for (int i = 0; i < n; i++)
  		{
  			for (int j = 0; j < n; j++)
  				{
  					if (cnt)
  						cout << 1;

  					else
  						cout << 2;

  					if (a[i][j] == 1)
  						cnt = max(--cnt, 0);
  				}
  			cout << endl;
  		}
}
