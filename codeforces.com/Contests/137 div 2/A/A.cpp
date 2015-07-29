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

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	int n, k;
	cin >> n >> k;

	vector <int> a(n);

	int cnt = 1;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = n - 1; i > 0; i--)
		if (a[i] == a[i - 1])
			cnt++;
		else
			break;

	if (cnt <= n - k)
		{
			cout << -1;
			return 0;
		}
	cout << n - cnt;
   return 0;
}



