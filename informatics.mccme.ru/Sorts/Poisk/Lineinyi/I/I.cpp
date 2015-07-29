#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector <vector <int> > a(n, vector <int> (m));
	vector <vector <pair <bool, bool> > > v
	(n, vector <pair <bool, bool> > (m, make_pair(false, false)));
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	for (int i = 0; i < n; i++)
		{
			int mn = 0;
			for (int j = 0; j < m; j++)
				if (a[i][j] < a[i][mn])
					mn = j;
			for (int j = 0; j < m; j++)
				if (a[i][mn] == a[i][j])
					v[i][j].first = true;
		}
	for (int j = 0; j < m; j++)
		{
			int mx = 0;
			for (int i = 0; i < n; i++)
				if (a[i][j] > a[mx][j])
					mx = i;
			for (int i = 0; i < n; i++)
				if (a[mx][j] == a[i][j])
					v[i][j].second = true;
		}

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (v[i][j].first && v[i][j].second)
				ans ++;
	cout << ans;
	return 0;
}
