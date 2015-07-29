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
#define File "kingwalk"

int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};

int dp[30][30][60], pr[30][30][60];

int n, m;

bool ok (int a, int b)
{
	if (a >= 0 && a < n)
		if (b >= 0 && b < m)
			return true;

	return false;
}

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	cin >> n >> m;

	vector <string> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int len;

	cin >> len;

	string s;

	cin >> s;

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				{
					if (a[i][j] == s[0])
						dp[i][j][0] = 1;
					else
						dp[i][j][0] = 0;

				  	for (int k = 0; k < len; k++)
				  		pr[i][j][k] = -1;
				}

		}

	for (int k = 1; k < len; k++)
		{
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					{
						int ans = -1;
						int p = -1;
						for (int q = 0; q < 8; q++)
							{
								int tmpx = i + dx[q];
								int tmpy = j + dy[q];

								if (ok(tmpx, tmpy))
									{
										if (ans < dp[tmpx][tmpy][k - 1])
											{
												p = q;
												ans = dp[tmpx][tmpy][k - 1];
											}
									}
							}

						if (a[i][j] == s[k])
							ans++;

						dp[i][j][k] = ans;	
						pr[i][j][k] = p;
					}
		}

	int ans = -1, x = -1, y = -1;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			{
				if (dp[i][j][len - 1] > ans)
					{
						ans = dp[i][j][len - 1];
						x = i;
						y = j;
					}
			}

	cout << ans << endl;

	int c = len - 1;

	vector <PII> ansv;

	while (c >= 0)
		{
			ansv.push_back(MP(x + 1, y + 1));
			int p = pr[x][y][c];

			if (x < 0 || y < 0)
				{
					cout << "ASDas";
					return 0;
				}
			x += dx[p];
			y += dy[p];
			c--;
		}

	for (int i = len - 1; i >= 0; i--)
		cout << ansv[i].F << ' ' << ansv[i].S << endl;

	return 0;
}
