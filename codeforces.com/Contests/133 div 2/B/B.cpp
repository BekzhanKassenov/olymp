/*********************************************
**       Solution by Bekjan Kasenov         **
**********************************************/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <cstdlib>
#include <cmath>
#include <limits.h>
#include <ctime>

using namespace std;

#define abs(x) (x < 0) ? (-x) : x
#define sqr(x) (x) * (x)
#define INF 1000000000
#define EPS 10e-14
#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define VI vector <int>

vector <bool> used, dr;

vector <int> col;

vector <vector <int> > a;

int n;

void init()
{
	used.assign(n, false);
	dr.assign(n,false);
	a.resize(n);
	col.assign(n, 0);
}

bool flag = false;

void dfs(int v, int color)
{
	used[v] = true;
	col[v] = color;
	color = 3 - color;
	//cout << v + 1 << ' ' << col[v] << endl;
	if (a[v].empty())
		return;
	for (int i = 0; i < a[v].size(); i++)
		if (!used[a[v][i]])
			dfs(a[v][i], color);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	int m;
	cin >> n >> m;
	init();
	int x, y;
	for (int i = 0; i < m; i++)
		{
			cin >> x >> y;
			x--; 
			y--;
			a[x].PB(y);
			a[y].PB(x);
		}

	
	for (int i = 0; i < n; i++)
		if (!used[i])
			{
				//cout << "dfs " << i << ":" << endl;
				dfs(i, 1);
				flag = false;
		   }
	
	for (int i = 0; i < n; i++)  
		for (int j = 0; j < a[i].size(); j++)
			if (used[a[i][j]] && col[i] == col[a[i][j]] && !dr[a[i][j]] && !dr[i])
				dr[i] = true;
   
   int ans = 0;
	for (int i = 0; i < n; i++)
		{
			ans += dr[i];
			//cout << i + 1 << " : " << dr[i] << " : " << col[i] << endl;
		}
	cout << ans + ((n - ans) % 2);
	return 0;
}
