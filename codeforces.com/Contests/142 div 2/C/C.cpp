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
#define VI vector <int>
#define LL long long
#define ULL unsigned long long

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	
	int n, m;
	cin >> n >> m;

	vector <vector <int> > a(n, vector <int> (m));

	vector <vector <int> > ans(n, vector <int> (m, 2000000000));

	vector <vector <int> > ons(n);

	for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			for (int j = 0; j < m; j++)
				if (s[j] == '0')
					a[i][j] = 0;
				else
					{
						a[i][j] = 1;
						ons[i].PB(j);
					}
		} 

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				{
					vector <int> :: iterator k = lower_bound(ons[i].begin(), ons[i].end(), i);
					int z = -1;
					
					if (k != ons[i].end())
						z = *k;
					
					k = upper_bound(ons[i].begin(), ons[i].end(), i);
					
					int q = -1;
					if (k != ons[i].end())
				    	q = * k;
				   if (z == -1 && q == -1)
				   	{
				   		cout << -1;
				   		return 0;
				   	}
				   if (q != -1)
				  		ans[i][j] = abs(j - q);
				  	if (z != -1)
				  		ans[i][j] = min(ans[i][j], abs(j - z));
				}	
		}

	int q = 20000000;

	for (int i = 0; i < n; i++)
		{
			int mx = -1;
			for (int j = 0; j < m; j++)
				mx = max(mx, ans[i][j]);
			if (mx != -1)
				q = min(q, mx);
		}
	cout << q;
	return 0;
}
