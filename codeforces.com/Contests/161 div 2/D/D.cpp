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

int k;

vector <VI> g;

vector <int> color;

vector <int> path;

vector <int> d;

int wh = -1;

bool flag = false;

void dfs(int v, int gl = 1)
{
	color[v] = 1;         
	d[v] = gl;

	for (int i = 0; i < (int)g[v].size(); i++)
		{
			int to = g[v][i];

			if (!color[to])
				{
					dfs(to, gl + 1);

					if (wh != -1)
						{
							path.push_back(v);

							if (wh == v)
								wh = -1;

							break;	
						}
				}
			else	
				if (color[to] == 1)
					{
						if (d[v] - d[to] >= k)
							{
								path.push_back(v);

								wh = to;

								flag = true;

								break;
							}
					}

			if (flag)
				return;
		}

	color[v] = 2;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, m;

	scanf("%d%d", &n, &m);

	scanf("%d", &k);

	g.resize(n);

	for (int i = 0; i < m; i++)
		{
			int a, b;

			scanf("%d%d", &a, &b);

			a--, b--;

			g[a].push_back(b);
			g[b].push_back(a);
		}

	color.resize(n, 0);

	d.resize(n);

	for (int i = 0; i < n; i++)
		{
			if (!path.empty())
					break;
			if (!color[i])
				dfs(i);
		}

  	cout << path.size() << endl;

  	for (int i = 0; i < (int)path.size(); i++)
  		cout << path[i] + 1 << ' ';

	return 0;
}
