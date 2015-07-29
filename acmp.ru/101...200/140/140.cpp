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
	vector <vector <int> > d(n, vector <int> (n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> d[i][j];

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (d[i][k] <= 10000 && d[k][j] <= 10000)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	for (int i = 0; i < n; i++)
		if (d[i][i] < 0)
			{
				cout << "YES";
				return 0;
			}
   cout << "NO";
   return 0;
}
