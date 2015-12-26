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
#define INF (int)2e9
#define MOD
#define EPS
#define File "area"

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int n;

	cin >> n;

	vector <PII> c(n);

	for (int i = 0; i < n; i++)
		cin >> c[i].F >> c[i].S;

	int ans = 0;

	for (int i = 2; i < n; i++)
		{
			int tx = c[i].F - c[0].F;
			int ty = c[i].S - c[0].S;

			int _x = c[i - 1].F - c[0].F;
			int _y = c[i - 1].S - c[0].S;

			ans += (tx * _y - ty * _x);
		}

	/*if (n != 3)
		{
			int tx = c[n - 1].F - c[0].F;
			int ty = c[n - 1].S - c[0].S;
	
			int _x = c[1].F - c[0].F;
			int _y = c[1].S - c[1].S;

			ans += tx * _y - ty * _x;
		}*/	

	cout << fabs(double(ans) / 2);

	return 0;
}
