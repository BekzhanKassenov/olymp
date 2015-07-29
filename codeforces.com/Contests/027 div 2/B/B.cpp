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
#define VII vector <VI>

VII g;

int n;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> n;
	
	g.assign (n, VI(n, 0));

	int x, y;

	for (int i = 0; i < (n * (n - 1)) / 2 - 1; i++)
		{
			cin >> x >> y;

			x--;
			y--;

			g[x][y] = 1;
			g[y][x] = -1;
		}

	int a, b;

	for (int i = 0; i < n; i++)
		{
			bool flag = false;
			for (int j = 0; j < n; j++)
				{
					if (!g[i][j] && i != j)
						{
							a = i, b = j;
							flag = true;
							break;
						}
				} 
			if (flag)
				break;
		}

	for (int i = 0; i < n; i++)
		{
			if (g[a][i] != g[b][i])
				{
					if (g[a][i] == 1)
						{
							cout << a + 1 << ' ' << b + 1 << endl;
						}
					else
						{
							cout << b + 1 << ' ' << a + 1 << endl;
						}
					return 0;
				}
		}

	cout << a + 1 << ' ' << b + 1 << endl;

	return 0;
}
