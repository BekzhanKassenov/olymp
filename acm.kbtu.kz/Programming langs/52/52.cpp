#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;

	vector <vector <int> > a(n, vector <int> (m, 0));

	vector <vector <int> > d(n, vector <int> (m,200000000));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	d[0][0] = a[0][0];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			{
				if (i > 0)
					d[i][j] = min(d[i][j], d[i - 1][j]);
				if (j > 0)
					d[i][j] = min(d[i][j], d[i][j - 1]);
				if (!(i == 0 && j == 0))
				d[i][j] += a[i][j];
			}
	cout << d[n - 1][m - 1];
	return 0;
}
