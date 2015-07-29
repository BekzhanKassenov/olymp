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
#define VI vector <int>

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	int a, b, c;
	cin >> a >> b >> c;
	int k = b;
	int ans = b * c;
	int res = 0;
	for (int i = 1; i <= a; i++)
		res += b, b++;
	res *= 2;
	res += (c - a - 1) * (b - 1);
	cout << res << endl;
	b = k;
	a--;
	 
	while (a)
		{
			ans += (b + c - 1);
			a--;

		}
		cout << ans;
	return 0;
}