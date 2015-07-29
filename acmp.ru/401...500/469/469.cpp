#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define INF 1000000

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n, m;
	cin >> n >> m;
	vector <vector <int> > g(n, vector <int> (m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> g[i][j];
	vector <vector <int> > d(n, vector <int> (m,INF));
	d[0][0] = g[0][0];
	bool stopFlag = false;
	while (!stopFlag)
		{
			bool any = false;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					{
						if (i > 0 && d[i - 1][j] > d[i][j] + g[i - 1][j])
							{
								d[i - 1][j] = d[i][j] + g[i - 1][j];
								any = true;
							}
						if (i < n - 1 && d[i + 1][j] > d[i][j] + g[i + 1][j])
							{
								d[i + 1][j] = d[i][j] + g[i + 1][j];
								any = true;
							}
						if (j > 0 && d[i][j - 1] > d[i][j] + g[i][j - 1])
							{
								d[i][j - 1] = d[i][j] + g[i][j - 1];
								any = true;
							}
						if  (j < m - 1 && d[i][j + 1] > d[i][j] + g[i][j + 1])
							{
								d[i][j + 1] = d[i][j] + g[i][j + 1];
								any = true;
							}
					}
		   if (!any)
		   	stopFlag = true;
		}
   cout << d[n - 1][m - 1];
   return 0;
}
