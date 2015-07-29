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

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	int a[3] = {0};

	int tmp;
	
	for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			a[i % 3] += tmp;
		}

	if (a[0] > a[1] && a[0] > a[2])
		{
			cout << "chest" ;
			return 0;
      }

   if (a[1] > a[0] && a[1] > a[2])
   	{
   		cout << "biceps";
   		return 0;
   	}

   if (a[2] > a[0] && a[2] > a[1])
   	{
   		cout << "back" ;
   		return 0;
   	}


	return 0;
}
