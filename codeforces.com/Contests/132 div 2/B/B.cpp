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
#include <algorithm>
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
#define int long long
#define VI vector <int>

main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	
	int n;
	scanf("%I64d", &n);
	VI a(n);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	
	int m;
	scanf("%I64d", &m);
	VI b(m);
	for (int i = 0; i < m; i++)
		scanf("%I64d", &b[i]);

	int l;
	scanf("%I64d", &l);
	VI c(l);
	for (int i = 0; i < l; i++)
	   scanf("%I64d", &c[i]);

	double x, y;
	cin >> x >> y;

	double ans = 0;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());

	ans = (x * c[0]) / (y * b[m - 1]);
	ans += 1;
	ans = (1 / ans);
	ans = sqrt(ans);
	ans *= a[n - 1];
	
  	printf("%.15lf", ans);
}
