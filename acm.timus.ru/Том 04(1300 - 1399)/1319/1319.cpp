#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n;

bool ok(int a)
{
	return (a >= 0 && a < n);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
  	#endif

  	cin >> n;

  	vector <vector <int> > a(n, vector <int> (n));

  	int nmb = 1;

  	for (int i = n - 1; i >= 0; i--)
  		{
  			int x = 0, y = i;

  			while (ok(x) && ok(y))
  				{
  					a[x][y] = nmb++;
  					x++;
  					y++;
  				}
  		}
	
	for (int i = 1; i < n; i++)
		{
			int x = i, y = 0;

			while (ok(x) && ok(y))
				{
					a[x][y] = nmb++;
					x++;
					y++;
				}
		}

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << a[i][j] << ' ';

			cout << endl;	
		}

	return 0;
}


