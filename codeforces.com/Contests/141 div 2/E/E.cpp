/*********************************************
**       Solution by Bekzhan Kasenov        **
**********************************************/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <limits.h>
#include <ctime>


using namespace std;

#define abs(x) (x < 0) ? (-x) : x
#define sqr(x) (x) * (x)
#define INF 2000000000
#define EPS 10e-14
#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define VI vector <int>

int n, m;

struct tk
{
	vector <vector <int> > F;
	vector <int> S;
};

bool operator ==(vector <vector <int> >& a, vector <vector <int> >& b)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] != b[i][j])
				return false;

	return true;
}

bool operator < (const tk& a, const tk& b)
{
	if (a.S.size() < b.S.size())
		return true;
	if (a.S.size() > b.S.size())
		return false;
	return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	
	cin >> n >> m;
	
	vector <vector <int> > g(n, vector <int> (n));

	int x, y, z;
	for (int i = 0; i < m; i++)
		{
			cin >> x >> y >> z;
			g[--x][--y] = z;
			g[y][x] = z;
		}

	vector <vector <int> > ed(n, vector <int> (n, 1));

	for (int i = 0; i < n; ++i)
		ed[i][i] = 0;

	tk tmp;
	tmp.F = ed;

	queue <tk> q;
	
	q.push(tmp);
	
	map <tk , bool> used;

	used[tmp] = true;
	
	while (!q.empty())
		{
			tmp = q.front();
			q.pop();
			if (tmp.F == g)
				{
					for (int i = 0; i < (int)tmp.S.size(); i++)
						cout << tmp.S[i] + 1 << ' ';
					return 0;
				}
			else
				if ((int)tmp.S.size() < n - 1)
					{
						for (int i = 0; i < n; i++)
							{
								tk z = tmp;
								z.S.push_back(i);
								for (int j = 0; j < n; j++)
									{
										if (i != j)	
											z.F[i][j] = z.F[j][i] = 1 - z.F[i][j];
									}
								if (used[z] == false)
									{
										used[z] = true;
										q.push(z);
									}
							}
					}
		}
	cout << "IMPOSSIBLE";

	return 0;
}
