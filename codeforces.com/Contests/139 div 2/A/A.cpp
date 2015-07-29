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

bool operator == (PII a, PII b)
{
	if (a.F == b.F && b.S == a.S)
		return true;
	if (a.S == b.F && b.S == a.F)
		return true;
	return false;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	int n,k;
	cin >> n >> k;
	vector <PII> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].F >> a[i].S;
 	
 	PII z = MP(k, 7 - k);
 	for (int i = 1; i < n; i++)
 		{
 			if (a[i] == MP(2, 3) || a[i] == MP(3, 5) || a[i] == MP(5, 4) || a[i] == MP(2, 4))
 				{
 					PII b = MP(1, 6);
 					if (!(b == z))
 						{
 							cout << "NO";
 							return 0;
 						}	
 				}
 			if (a[i] == MP(1, 4) || a[i] == MP(4, 6) || a[i] == MP(6, 3) || a[i] == MP(1, 3))
 				{
 					PII b = MP(5, 2);
 					if (!(b == z))
 						{
 							cout << "NO";
 							return 0;
 						}	
 				}
 			if (a[i] == MP(1, 5) || a[i] == MP(5, 6) || a[i] == MP(6, 2) || a[i] == MP(1, 2))
 				{
 					PII b = MP(3, 4);
 					if (!(b == z))
 						{
 							cout << "NO";
 							return 0;
 						}	
 				}
 		}
 	cout << "YES";
 	return 0;
}