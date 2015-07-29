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
#define File "billboard" 

int u[4] = {1, 0, 0, -1};
int d[4] = {0, 1, -1, 0};

int k, n, m;

vector <vector <vector <bool> > > g;

vector <vector <bool> > used;

bool operator == (const vector <bool> &a, const vector <bool> &b)
{
	for (int i = 0; i < k; i++)
		if (a[i] != b[i])
			return false;

	return true;
}

void dfs(int x, int y)
{
	used[x][y] = true;
	for (int i = 0; i < 4; i++)
		{
			int nx = x + u[i];
			int ny = y + d[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
				{
					if (!used[nx][ny] && g[nx][ny] == g[x][y])
						dfs(nx, ny);
				}
		}
}

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	cin >> k >> n >> m;

	g.assign(n, vector <vector <bool> > (m, vector <bool> (k, false)));

	used.assign(n, vector <bool> (m, false));

	char ch;

	for (int q = 0; q < k; q++)
		{
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					{
						cin >> ch;
						if (ch == '*')
							g[i][j][q] = true;
					}
		}

	int ans = 0;

	set <vector <bool> > s;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			{
				s.insert(g[i][j]);
			}

	cout << s.size();;
	return 0;
}
