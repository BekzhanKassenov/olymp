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
#define INF 1000000000
#define EPS 10e-14
#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define LL long long
#define ULL unsigned long long

ULL n;

ULL s(LL n)
{
	LL ans = 0;
	while (n)
		{
			ans += n % 10;
			n /= 10;
		}
	return ans;	
}

ULL check(ULL c)
{
	ULL ans = INF * 1ll * INF;
	ULL d = c * c + 4 * n;

	ULL k = sqrt(d);
	
	if (k * k == d)
		{
			ULL x1 = (-c + k);
			if (x1 % 2 == 0 && x1 > 0)
				{
					if (s(x1 / 2) == c)
						ans = min(ans, x1 / 2);
				}
		}
	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	
	cin >> n;

	ULL ans = INF * 1ll * INF;

	for (int i = 0; i <= 99; i++) 

		{
			ans = min(ans, check(i));
		}

  	if (ans != INF * 1ll * INF)
		cout << ans;
  	else
  		cout << -1;
	return 0;
}

