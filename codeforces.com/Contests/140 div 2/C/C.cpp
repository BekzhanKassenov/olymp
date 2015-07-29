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
#define int long long

int  m;

int pw(int n, int st)
{

	//cout << n << ' ' << st << endl;	

	if (st == 0)
		return 1;

  	if (st == 1)
  		return n;

	if (st % 2 == 1)
		{
			return ((n * pw(n, st - 1)) % m);
		}
	else
		{
			int k = pw(n, st / 2);
			return ((k * k) % m);
		}
}

main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	
	
	int n;

	cin >> n >> m;

  	int ans = (pw(3, n) - 1);

	cout << (ans + m) % m;
	
}
