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
	
	int s;
	
	int n;
	
	cin >> s >> n;

	vector <PII> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i].F >> a[i].S;

	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++)
		{
			if (s <= a[i].F)
				{
					cout << "NO";
					return 0;
				}
			else
				{
					s += a[i].S;
				}	
		}
	cout << "YES";;
	return 0;
	return 0;
}
