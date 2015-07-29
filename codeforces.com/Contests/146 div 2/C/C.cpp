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

LL gcd(LL a, LL b)
{
	if (a == 0 || b == 0)
		return a + b;

	if (a > b)
		return gcd(a % b, b);
	else
		return gcd(b % a, a);
}

LL lcm(LL a, LL b)
{
	return (a / gcd(a, b)) * b;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	
	LL n;

	cin >> n;

	if (n == 1)
		{
			cout << 1;
			return 0;
		}
	if (n == 2)
		{
			cout << 2;
			return 0;
		}
	
	if (n % 2 == 1)
		{
			cout << n * (n - 1) * (n - 2);
			return 0;
		}
	else
		{
		   if (n % 3 == 0)
		   	{
		   		LL ans = (n - 1) * (n - 2) * (n - 3);
		   		cout << ans << endl;
		   	}
		   else
		   	{
		   		cout << n * (n - 1) * (n - 3);
		   	}
			return 0;
		}

	return 0;
}
