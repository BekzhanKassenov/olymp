#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n, m;
	cin >> n >> m;
	int x,y;
	vector <vector <int> > g(n, vector <int> (n));
	for (int i = 0; i < m; i++)	
		{
			cin >> x >> y;
			x--;
			y--;
			g[x][y] = 1;
		}
	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)	
				cout << g[i][j] << ' ';
			cout << endl;
		}
	return 0;
}
