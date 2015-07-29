/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define sqr(x) (x) * (x)
#define INF (int) (2e9)
#define MOD (1000 * 1000 * 1000 + 7)
#define ull unsigned long long
#define ll long long

vector <vector <int> > g;

int n;

vector <bool> used;

void dfs(int v)
{
	used[v] = true;

	for (int i = 0; i < n; i++)
		if (g[v][i] && !used[i])
			dfs(i);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int m;
	
	cin >> n >> m;

	g.resize(n, vector <int> (n));

	vector <vector <int> > y(n, vector <int> (m));

	bool flag = true;

	for (int i = 0; i < n; i++)
		{
			int k;

			cin >> k;

			if (k > 0)
				flag = false;

			int tmp;

			for (int j = 0; j < k; j++)
				{
					cin >> tmp;
					y[i][tmp - 1] = true;
				}
		}

	if (flag)
		{
			cout << n;
			return 0;
		}

	for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
				{
					for (int k = 0; k < m; k++)	
						{
							if (y[i][k] && y[j][k])
								{
									g[i][j] = g[j][i] = 1;
									break;
								}
						}
				}
		}

	used.assign(n, 0);

	int ans = 0;

	for (int i = 0; i < n; i++)
		if (!used[i])
			{
				dfs(i);
				ans++;
			}

   	cout << ans - 1;

	return 0;
}
