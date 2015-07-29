/********************************************
***     Solution by Bekzhan Kassenov      ***
********************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <assert.h>

using namespace std;

#define sqr(x) (x) * (x)
#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define VII vector <VI>
#define ll long long
#define ull unsigned long long
#define INF
#define MOD
#define EPS
#define File "bwsquare"

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int n, m;

	cin >> n >> m;

	vector <vector <int> > a(n + 10, vector <int> (m + 10));

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		}

	vector <vector <int> > g = a;

	vector <int> ans, ans1;

	for (int j = 0; j < m; j++)
		{
			bool bad = true;

			for (int i = 0; i < n; i++)
				if (a[i][j] == 0)
					{
						bad = true;
						break;
					}
				else
					if (a[i][j] == 1)
						bad = false;

			if (bad)
				continue;

			for (int i = 0; i < n; i++)
				a[i][j] = 2;

			ans.push_back(j + 1);	
		}


	for (int i = 0; i < n; i++)
		{
			bool bad = true;

			for (int j = 0; j < m; j++)
				{
					if (a[i][j] == 0)
						{
							bad = true;
					   	break;
						}
					else
						if (a[i][j] == 1)
							bad = false;
			  	}

			if (bad)
				continue;

			for (int j = 0; j < m; j++)
				a[i][j] = 2;

			ans.push_back(-i - 1);
		}


	for (int i = 0; i < n; i++)
		{
			bool bad = true;

			for (int j = 0; j < m; j++)
				{
					if (g[i][j] == 0)
						{
							bad = true;
					   	break;
						}
					else
						if (g[i][j] == 1)
							bad = false;
			  	}

			if (bad)
				continue;        

			for (int j = 0; j < m; j++)
				g[i][j] = 2;

			ans1.push_back(-i - 1);
		}

	for (int j = 0; j < m; j++)
		{
			bool bad = true;

			for (int i = 0; i < n; i++)
				if (g[i][j] == 0)
					{
						bad = true;
						break;
					}
				else
					if (g[i][j] == 1)
						bad = false;

			if (bad)
				continue;

			for (int i = 0; i < n; i++)
				g[i][j] = 2;

			ans1.push_back(j + 1);	
		}
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == 1)
				{
					cout << -1;
					return 0;
				}

	if (ans1.size() < ans.size())
		ans = ans1;

	cout << ans.size() << endl;
	
	for (int i = 0; i < (int)ans.size(); i++)
		cout << ans[i] << ' ';

	return 0;
}
