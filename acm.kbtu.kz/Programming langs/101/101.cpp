#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define INF 2000000000

int main()
{
	int n;
	cin >> n;
	vector <vector <int> > a(n, vector <int> (n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
				if (a[i][j] == -1)
					a[i][j] = INF;
			}

  	for (int k = 0; k < n; k++)
  		for (int i = 0; i < n; i++)
  			for (int j = 0; j < n; j++)
  				if (i != j && i != k && j != k && a[i][k] < INF && a[k][j] < INF)
  					a[i][j] = min(a[i][k] + a[k][j], a[i][j]);

  	int ans = -INF;
  	
  	for (int i = 0; i < n; i++)
  		for (int j = 0; j < n; j++)
  			if (a[i][j] < INF)
  				ans = max(ans, a[i][j]);

  	cout << ans;
  	
  	return 0;
}
	
