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
#include <algorithm>
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
	int n, k;
	cin >> n >> k;
	VI a(2 * n + 1);
	int s = 2 * n + 1;
	for (int i = 0; i < s; i++)
		cin >> a[i];
	for (int i = 0; i < s; i++)
		{
			if ((i + 1) % 2 == 0)
				{
					if (a[i] - 1 > a[i - 1] && a[i] - 1 > a[i + 1])
						{
							a[i] -- ;
							k--;
						}
				}
			if (!k)
				break;
		}
  	for (int i = 0; i < s;  i++)
  		cout << a[i] << ' ';
	return 0;
}
