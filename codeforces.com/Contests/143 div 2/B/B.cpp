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
	
	int n, d, l;

	cin >> n >> d >> l;

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		a[i] = l;

	int tmp;

	if (n % 2 == 0)
		{
			tmp = 0;
		}
	else
		tmp = l;

	int s;

	if (tmp < d)
		s = 1;
	else
		s = 0;

	for (int i = s; i < n; i += 2)
		{
			while (tmp != d && a[i] > 1)
				{
					if (tmp > d)
						tmp--;
					else
						tmp++;

					a[i]--;
				}
		}

	if (tmp != d)
		{
			cout << -1;
			return 0;
		}
	else
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';

	return 0;
}
