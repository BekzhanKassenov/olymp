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

int d[8] = {1, 1,  1,  0, -1, -1, -1, 0};
int u[8] = {1, 0, -1, -1, -1,  0,  1, 1};

int n, m;

bool ok(int x, int y)
{
	if (x >= 0 && x < n)
		if (y >= 0 && y < m)
			return true;

	return false;
}

int main()
{  
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> n >> m;

	vector <vector <int> > a(n, vector <int> (m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

  	vector <bool> used(101, false);

	int ans = 0;

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				{
					if (a[i][j] == -1)
						continue;

					int tmp = 0;

					for (int k = 0; k < 8; k++)
						{
							int cur_i = i + u[k];
							int cur_j = j + d[k];

							if (ok(cur_i, cur_j))
								if (a[cur_i][cur_j] == a[i][j])
									tmp++;
						}
					if (tmp > 0 && !used[a[i][j]])
						{
							used[a[i][j]] = true;
							ans++;
						}
				}
		}

	cout << ans;	

	return 0;
}
