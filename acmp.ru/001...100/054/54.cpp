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

	vector <vector <int> > a(n, vector <int> (m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)	
			cin >> a[i][j];

	int nz = -2000;

  	for (int i = 0; i < n; i++)
  		{
  			int mn = 2000;
  			for (int j = 0; j < m; j++)
  				mn = min(a[i][j], mn);

  			nz = max(nz, mn);
  		}


  	int v = 2000;

  	for (int j = 0; j < m; j++)
  		{
  			int mx = -2000;

  			for (int i = 0; i < n; i++)
  				mx = max(mx, a[i][j]);

  			v = min(v, mx);
  		}

  	cout << nz << ' ' << v;

  	return 0;
}
