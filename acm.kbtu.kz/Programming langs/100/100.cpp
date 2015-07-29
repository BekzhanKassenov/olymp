#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <vector <int> > a(n, vector <int> (n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

  	for (int k = 0; k < n; k++)
  		for (int i = 0; i < n; i++)
  			for (int j = 0; j < n; j++)
  				if (i != j && i != k && j != k)
  					a[i][j] = min(a[i][k] + a[k][j], a[i][j]);

  	for (int i = 0; i < n; i++)
  		{
  			for (int j = 0; j < n; j++)
  				cout << a[i][j] << ' ';
  			cout << endl;
  		}

  	return 0;
}
	
