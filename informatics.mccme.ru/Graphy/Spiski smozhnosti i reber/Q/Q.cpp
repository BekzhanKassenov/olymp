#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	cin >> n >> m;
	vector <vector <int> > g(n, vector <int> (n));
	int x, y;
	for (int i = 0; i < m; i++)
		{
			cin >> x >> y;
			x--;
			y--;
			g[x][y] = 1;
			g[y][x] = 1;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (g[i][j] == 0 && i!=j)
				{
					cout << "NO";
					return 0;
				}
	cout << "YES";
	return 0;
}
