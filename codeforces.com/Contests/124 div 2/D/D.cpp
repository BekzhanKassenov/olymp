#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define PII pair <int, int>
#define MP make_pair
#define F first
#define S second

int u[4] = {1, 0, 0, -1};
int d[4] = {0, 1, -1, 0};

int mod(int n, int m)
{
	while (n < 0)
		n += m;

	return (n % m);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, m;

	cin >> n >> m;

	vector <vector <int> > g(n, vector <int> (m));

	char c;

	int x, y;

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				{
					cin >> c;

					if (c == '#')
						{
							g[i][j] = 1;
						}

					if (c == '.')	
						{
							g[i][j] = 0;
						}

					if (c == 'S')
						{
							x = i;
							y = j;
							g[i][j] = 0;
						}
				}
		}

	queue <PII> q;

	q.push(MP(x, y));

	vector <vector <PII> > used(n, vector <PII> (m, MP(-1, -1)));

	while (!q.empty())
		{
			PII now = q.front();

			q.pop();

			//cout << now.F << ' ' << now.S << endl;

			for (int j = 0; j < 4; j++)
				{
					x = now.F + u[j];
					y = now.S + d[j];

					PII t = MP(x, y);

					int z = mod(x, n);
					int w = mod(y, m);

					if (g[z][w] == 1)
						continue;
				  	
				  	if (used[z][w] == MP(-1, -1))
				  		{
				  			used[z][w] = t;
				  			q.push(t);
				  			continue;
				  		}
				  	else
				  		{
				  			if (used[z][w] != t)
				  				{
				  					cout << "Yes";
				  					return 0;
				  				}
				  		}
				}
		}

	cout << "No";
	return 0;
}
