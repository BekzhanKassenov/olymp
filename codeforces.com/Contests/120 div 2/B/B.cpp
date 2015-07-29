/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define sqr(x) (x) * (x)
#define INF (int) (2e9)
#define MOD (1000 * 1000 * 1000 + 7)
#define ull unsigned long long
#define ll long long

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int x, y, r, _x, _y, _r;

	cin >> x >> y >> r >> _x >> _y >> _r;

	double dist = sqrt(sqr(_x - x) + sqr(_y - y));

	if (r + _r > dist && max(r, _r) - min(r, _r) < dist)
		{
			puts("0");
			return 0;
		}

	if (dist < r || dist < _r)
		{
			printf("%.10lf", (max(r, _r) - dist - min(r, _r)) / 2);
			return 0;
		}

	if (r + _r <= dist)
		{
			printf("%.10lf", (dist - r - _r) / 2);
			return 0;
		}

	return 0;
}
