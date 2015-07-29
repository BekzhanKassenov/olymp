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
#define File "triangles"

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int n;

	scanf("%d", &n);

	vector <PII> a(n);

	map <int, set <int> > x, y;

	for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &a[i].F, &a[i].S);

			x[a[i].F].insert(a[i].S);
			y[a[i].S].insert(a[i].F);
		}


	long long ans = 0;

	for (int i = 0; i < n; i++)
		{
			ans += ((ll)x[a[i].F].size() - 1) * (ll)(y[a[i].S].size() - 1);
		}

	cout << ans;

	return 0;
}
