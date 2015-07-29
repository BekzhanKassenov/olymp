#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	vector <vector <int> > g(n, vector <int> (n));
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			{
				cin >> g[i][j];
				if (g[i][j] == 1)
					g[i][j] = -1;
				else
					g[i][j] = 100000000;
			}
	
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				g[i][j] = min (g[i][j], g[i][k] + g[k][j]); 
	
	for (int i = 0; i < n; i++)
		if (g[i][i] < 0)
			{
				cout << 1;
				return 0;
			}

	cout << 0;
	return 0;
}
