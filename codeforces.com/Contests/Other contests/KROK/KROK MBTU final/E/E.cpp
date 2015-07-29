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

int n, m; 
long long ans = -1;

void solve(int etazh, int cur_x, int napr)
{
	ans++;
	if (etazh == n)
		return;

	if (g[etazh + 1][cur_x] == 0)
		{
			solve(etazh + 1, cur_x, napr);
			return;
		}

	int l = -1, r = -1;

	map <PII, int> m;

	for (;;)
		{	
			if (l != -1 && r != -1)
				{
					if (napr == 1)
						cur_x = r;
					else
						cur_x = l;
				
					ans += abs(r - l);
			
				  	if (g[etazh + 1][cur_x] == 0)
		  				{
		  					solve(etazh + 1, cur_x, napr);
		  					return;
		  				}
		  		}

			int next_x = cur_x + napr;

			while (g[etazh][next_x] == 0)
				{
					cur_x = next_x;

					ans++;

					if (g[etazh + 1][cur_x] == 0)
				  		{
				  			solve(etazh + 1, cur_x, napr);
				  			return;
		  				}

					if (napr == 1)
						r = cur_x;
					else
						l = cur_x;
         		
         		next_x = cur_x + napr;	
				}

			if (g[etazh][next_x] == 1)
				g[etazh][next_x] = 0;

			napr *= -1;

			ans++;

			if (g[etazh + 1][cur_x] == 0)
		  		{
		  			solve(etazh + 1, cur_x, napr);
		  			return;
		  		}
	
		  	m[MP(l, r)] ++;

			if (m[MP(l, r)] >= 4)
				{
					cout << "Never";	
					exit(0);
				}
	  	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> n >> m;

	g.assign(n + 2, vector <int> (m + 2, 2));

	char c;

	getchar();

	for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				{
					c = getchar();
					switch (c)
						{
							case '.' : 
								g[i][j] = 0;
								break;
							case '+' : 
								g[i][j] = 1;
								break;
							case '#' : 
								g[i][j] = 2;
								break;
						}

				}
			getchar();
		}

	solve(1, 1, 1);

	cout << ans;
	return 0;
}
