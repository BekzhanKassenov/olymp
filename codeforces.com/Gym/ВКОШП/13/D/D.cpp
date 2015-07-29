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
#define EPS 1e-1
#define File "forest" 

int u[4] = {1, 0, 0, -1}; 
int d[4] = {0, 1, -1, 0};

int n, m;

bool check(int x, int y)
{
	if (x >= 0 && x < n)
		if (y >= 0 && y < m)
			return true;

	return false;
}

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	cin >> n >> m;

	vector <vector <int> > a(n, vector <int> (m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	int cnt = 0;

	set <pair <int, int> > s;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			s.insert(MP(i, j));

	int ans = 0;

	for (;;)
		{
			vector <PII> uv;

			for (set <PII> :: iterator it = s.begin(); it != s.end(); it++)
				{
					int x = it -> F;
					int y = it -> S;

					bool flag = false;
					for (int i = 0; i < 4; i++)
						{
							int nx = x + u[i];
							int ny = y + d[i];

							if (check(nx, ny))
							   {
									if (a[nx][ny] - a[x][y] == 1)
										flag = true;
								}
						}

					if (flag)
						uv.push_back(MP(x, y));

				}

			s.clear();

			for (int i = 0; i < (int)uv.size(); i++)
				{
					a[uv[i].F][uv[i].S]++;
					s.insert(uv[i]);
					for (int j = 0; j < 4; j++)
						{
							if (check(uv[i].F + u[j], uv[i].S + d[j]))
								{
									s.insert(MP(uv[i].F + u[j], uv[i].S + d[j]));
								}
						}
				}

			if (!s.empty())
				ans++;
			else
				break;
		}

	cout << ans << endl;

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cout << a[i][j] << ' ' ;
			cout << endl;
		}

	return 0;
}
