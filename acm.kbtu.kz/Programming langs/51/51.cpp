#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;

	vector <vector <int> > a(n, vector <int> (m, 0));

	a[0][0] = 1;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			{
				if (i > 0)
					a[i][j] += a[i - 1][j];
				if (j > 0)
					a[i][j] += a[i][j - 1];
			}
	cout << a[n - 1][m - 1];
	return 0;
}
