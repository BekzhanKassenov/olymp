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
#define VI vector <int>
#define LL long long
#define ULL unsigned long long

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	
	int ans = 0;

	int x, y, z;

	cin >> x >> y >> z;

	int xk, yk, zk;

	cin >> xk >> yk >> zk;

	int tmp;

	cin >> tmp;

	if (y < 0)
		ans += tmp;

	cin >> tmp;

	if (y > yk)
		ans += tmp;

	cin >> tmp;

	if (z < 0)
		ans += tmp;

	cin >> tmp;

	if (z > zk)
		ans += tmp;

	cin >> tmp;

	if (x < 0)
		ans += tmp;
	
	cin >> tmp;

	if (x > xk)
		ans += tmp;

	cout << ans;

	return 0;
}
