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
#define File "pyramid"

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int n;

	cin >> n;

	if (n == 1)
		{
			cout << 0;
			return 0;
		}

   vector <PII> a(n);

   vector <int> ans;

   for (int i = 0; i < n; i++)
   	scanf("%d%d", &a[i].F, &a[i].S);

   int mx = a[n - 1].F, mn = a[n - 1].S;

  	for (int i = n - 2; i >= 0; i--)
  		{
  			if (a[i].F >= mn || a[i].S < mx)
  				continue;                                                

  			ans.push_back(i);
  			mx = min(a[i].F, mx);
  			mn = max(a[i].S, mn);
  		}
                     
   printf("%d\n", ans.size());

   for (int i = 0; i < (int) ans.size(); i++)
   	printf("%d ", ans[i] + 1);

	return 0;
}
