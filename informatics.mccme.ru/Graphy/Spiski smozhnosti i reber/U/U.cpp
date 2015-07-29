#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	cin >> n;
	vector <vector <int> > g(n, vector <int> (n));
	int x,y;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> g[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (i!=j && j!=k && i!=k)
					if (g[i][j] && g[j][k] && !g[i][k])
						{
							cout << "NO";
							return 0;
						}
	cout << "YES";
	return 0;
}

