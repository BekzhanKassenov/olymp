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

long long kos(long long x, long long y, long long _x, long long _y)
{
	return (x * _y) - (_x * y);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	
	long long xa, ya, xb, yb, xc, yc;
	cin >> xa >> ya >> xb >> yb >> xc >> yc;

	long long k = kos(xa - xb, ya - yb, xc - xb, yc - yb);

	if (k == 0)
		{
			cout << "TOWARDS";
			return 0;
		}
	if (k < 0)
		{
			cout << "LEFT";
			return 0;
		}
	cout << "RIGHT";
	return 0;
}

