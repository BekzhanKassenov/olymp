/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define sqr(x) (x) * (x)
#define INF (int) (2e9)
#define MOD (1000 * 1000 * 1000 + 7)
#define ull unsigned long long
#define ll long long

const double pi = acos(-1.0);

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.rbegin(), a.rend());

	int uk = 0;

	double ans = 0;

	for (;;)
		{
			if (uk < n - 1)
				{
					ans += (sqr(a[uk]) - sqr(a[uk + 1])) * pi;
				}
			else
				{
					if (uk == n - 1)
						ans += sqr(a[uk]) * pi;

					break;
				}	
		   uk += 2;
		}

	printf("%.10lf", ans);

	return 0;
}
