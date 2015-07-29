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
#include <algorithm>
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

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	int n, m;
	cin >> n >> m;
	VI a(m);
	for (int i = 0; i < m; i++)
		cin >> a[i];
	int t1 = n;
	VI k = a;
	int ans = 0;
	int mx;
	while (n)
		{
			mx = 0;
			for (int i = 0; i < m; i++)
				if (a[i] > a[mx] || a[mx] == 0)
					mx = i;
			ans += a[mx];
			a[mx] --;
			n--;
		}
	cout << ans << ' ';
	int mn;
	ans = 0;
	while (t1)
		{
			mn = 0;
			for (int i = 0; i < m; i++)
				if ((k[i] < k[mn] && k[i] > 0) || k[mn] == 0 )
					mn = i;
		  	while (k[mn] > 0)
		   	{
		   		ans +=  k[mn];
		   		k[mn] --;
		   		t1--;
		   		if (!t1 || k[mn] == 0)
		   			break;
		   	}
		}
	cout << ans;
	return 0;
}

