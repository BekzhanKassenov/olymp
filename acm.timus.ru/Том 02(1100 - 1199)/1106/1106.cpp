#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

vector <int> col;

vector <vector <int> > g;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	srand(time(0));

	int n;

	cin >> n;

	if (n <= 1)
		{
			cout << 0;
			return 0;
		}

	col.assign(n + 2000, -1);

	g.resize(n + 2000);

	for (int i = 0; i < n; i++)
		{
			int x;
			
			cin >> x;

			while (x-- != 0)
				{
				   g[i].push_back(x);
				   g[x].push_back(i);
				   cin >> x;
				}
		}

	for (int i = 0; i < n; i++)
		{
			int color = 1 + (rand() & 1);

			for (size_t j = 0; j < g[i].size(); j++)
				if (col[g[i][j]] != -1)
					{
						color = 3 - col[g[i][j]];
						break;
					}

			col[i] = color;
		}

	for (int i = 0; i < n; i++)
		{
			bool flag = false;

			for (size_t j = 0; j < g[i].size(); j++)
				{
					if (col[g[i][j]] != col[i])
						flag = true;

					break;
				}

			if (!flag)
				col[i] = 3 - col[i];
		}

	int ans = 0;

  	for (int i = 0; i < n; i++)
  		if (col[i] == 1)
  			ans++;

 	cout << ans << endl;

	for (int i = 0; i < n; i++)
		if (col[i] == 1)
			cout << i + 1 << ' ';	

	return 0;
}
