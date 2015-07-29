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

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int x, y, n;

	cin >> x >> y >> n;

	if (n >= y)
		{
			cout << x << '/' << y;
			return 0;
		}
	else
		{
			double ans = 2e10;

			int ansa = -1, ansb = -1;

			double dd = (x + .0) / (y + .0);

			for (int b = 1; b <= n; b++)
				{
					int l = -1, r = (int)1e9 + 1;

					while (r - l > 1)
						{
							int m = (l + r) >> 1;

							double d = (m + .0) / (b + .0);

							if (abs(d - dd) < ans)
								{
									ans = abs(d - dd);
									ansa = m;
									ansb = b;
								}

							if (d > dd)
								r = m;
							else
								l = m;	
						}
				}
			cout << ansa << '/' << ansb << endl;
		}	

	return 0;
}
