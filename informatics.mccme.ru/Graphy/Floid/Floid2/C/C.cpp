#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define INF 100000000000.0

main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;

	vector <vector <double> > d(n, vector <double> (n));
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			{
				cin >> d[i][j];
				if (d[i][j] == 0)
					d[i][j] = INF;
			}

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (d[i][k] < INF && d[k][j] < INF)
					if (d[i][j] > d[i][k] + d[k][j])
						d[i][j] = max(-INF, d[i][k] + d[k][j]);

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				{
					bool w = false;
					if (i == j && d[i][j] >= 0)
						{
							cout << 1 << ' ';
							continue;
						}
					for (int k = 0; k < n; k++)
						if (d[k][k] < 0 && d[i][k] < INF && d[k][j] < INF)
							{
								w = true;
								cout << 2 << ' ';
								break;
							}
					if (!w && d[i][j] == INF)
						{
							w = true;
							cout << 0 << ' ';
						}
					if (!w)
						cout << 1 << ' ';
				}
			cout << endl;
		}
}
