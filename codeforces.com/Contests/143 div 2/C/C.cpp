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
	
	int n, k;
	
	cin >> n >> k;

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	vector <int> pp(n);

	for (int i = n - 2; i >= 0; i--)
		pp[n - 1] += (a[n - 1] - a[i]);

	for (int i = n - 2; i >= 0; i--)
		{
			pp[i] = pp[i + 1] - (i + 1) * (a[i + 1] - a[i]);
		}

	return 0;
}