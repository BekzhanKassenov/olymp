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
#define MOD 1073741824 

vector <int> c(10000001, -1);

int d(int n)
{
	if (c[n] != -1)
		return c[n];
	int k = sqrt(n);

	int ans = 0;

	for (int i = 1; i <= k; i++)
		{
			if (n % i == 0)
				{
					if (i * i != n)
						ans += 2;
					else
						ans++;	
				}
		}
	return c[n] = ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int a, b, c;

	cin >> a >> b >> c;

	int ans = 0;

	for (int i = 1; i <= a; i++)
		{
			for (int j = 1; j <= b; j++)
				{
					for (int k = 1; k <= c; k++)
						{
							ans += d(i * j * k) % MOD;
						}
				}
		}	
	cout << ans;

	return 0;
}
