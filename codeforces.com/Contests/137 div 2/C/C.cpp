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
#define SZ size()
#define VI vector <int>

VI lp;

vector <PII> pr;

void build()
{
	lp.resize(10000001);

	for (int i = 2; i < 10000001; i++)
		{
			if (lp[i] == 0)
				{
					lp[i] = i;
					pr.push_back(MP(i, 0));
				}
			for (int j = 0; j < (int)pr.size() && pr[j].F <= lp[i] && i * pr[j].F < 1000001; j++)
				lp[i * pr[j].F] = pr[j].F;
		}
}

void fact(int n, vector <int>& a)
{
	while (n > 1 && lp[n] != 0)
		{
			a[n / lp[n]]++;
			n /= lp[n];
		}

	if (n > 1)
		a[n]++;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, m;

	vector <int> a(n);

	vector <int> b(m);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);

	build();

	vector <int> af(10000000), bf = af;

	for (int i = 0; i < n; i++)
		fact(a[i], af);


	for (int i = 0; i < m; i++)
		fact(a[i], bf);


	for (int i = 0; i < 10000000; i++)
		if (af[i] > bf[i])
			af[i] -= bf[i];
		else
			bf[i] -= af[i];	


}
