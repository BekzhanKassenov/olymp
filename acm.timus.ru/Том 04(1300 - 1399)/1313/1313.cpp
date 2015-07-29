#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{	
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	vector <vector <int> > a(n, vector <int> (n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	for (int i = 0; i < n; i++)
		{
			for (int x = i, y = 0; x >= 0; x--, y++)
				cout << a[x][y] << ' ';
		}

	for (int i = 1; i < n; i++)
		{
			for (int x = n - 1, y = i; x >= 0 && y < n; x--, y++)
				cout << a[x][y] << ' ';
		}

	return 0;
}
