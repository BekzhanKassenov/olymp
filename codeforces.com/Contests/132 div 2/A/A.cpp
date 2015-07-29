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
#include <algorithm>
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
#define ll long long
#define VI vector <int>

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	int n;
	cin >> n;
	VI a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int m;
	cin >> m;
	VI b(m);
	for (int i = 0; i < m; i++)
		cin >> b[i];
	int ans = -1;
	vector <VI> d(n, VI(m));
	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--)
			{
				if (double (b[j]) / double(a[i]) == double(b[j] / a[i]))
					ans = max (d[i][j] = int (b[j] / a[i]), ans);	 
			}
	int k = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (d[i][j] == ans)
				k++;
	cout << k;
	return 0;
}
