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
#define int long long
#define ull unsigned long long
#define INF (int) 2e9
#define MOD
#define EPS

main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, x;

	cin >> n >> x;
	
	x--;

	VI a(n);

	int mn = INF;

	for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			mn = min(mn, a[i]);

		}

	for (int i = 0; i < n; i++)
		a[i] -= mn;

	int ans = mn * n;

	int pos = x;

	for (;;)
		{
			if (a[pos] != 0)
				{
					ans++;
					a[pos]--;
					pos = (pos - 1 + n) % n;
				}
			else
				{
					a[pos] = ans;
					break;
				}
		}


	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';

}
