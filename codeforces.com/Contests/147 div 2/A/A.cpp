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
#define PIS pair <int, string>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define VII vector <VI>
#define LL long long
#define ULL unsigned long long

int d[1500];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	
	int n;
	
	cin >> n;

	int x, y;

	int ans = 0;

	for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			y += x * 60;
			d[y]++;
		}

  	for (int i = 0; i < 1500; i++)
  		{
  			ans = max(ans, d[i]);
  		}
  	cout << ans;

	return 0;
}
