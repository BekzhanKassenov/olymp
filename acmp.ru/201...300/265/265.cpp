#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a[10][10] = {0};

	int n;

	cin >> n;

	vector <pair <int, int> > g(n);

	for (int i = 0; i < n; i++)
		{
		   cin >> g[i].first >> g[i].second;
			a[g[i].first][g[i].second] = 1;
		}

	int ans = 0;

	for (int i = 0; i < n; i++)
		{
			ans += 4;

			if (a[g[i].first - 1][g[i].second])
				ans--;

			if (a[g[i].first + 1][g[i].second])
				ans--;

			if (a[g[i].first][g[i].second + 1])
				ans--;

			if (a[g[i].first][g[i].second - 1])
				ans--;
		}

  	cout << ans;

  	return 0;
}

