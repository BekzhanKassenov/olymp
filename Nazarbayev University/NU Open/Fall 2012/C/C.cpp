/***************************************
**    Solution by Bekzhan Kassenov    **
**    For: NU Opean Fall 2012         **
***************************************/
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
#define int long long 
#define ull unsigned long long
#define File "divisibility"

main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int n;

	cin >> n;

	int m, p;

	cin >> m >> p;

	vector <int> a(m);

	bool pi = false;

	for (int i = 0; i < m; i++)
		{
			cin >> a[i];
			pi = pi | (a[i] == p);
		}

	int ans = n;

	int ans1 = n / p;

	for (int mask = 1; mask < (1 << m); mask++)
		{
			int cnt = 0;

			int tmp = 1;

			for (int i = 0; i < m; i++)
				{
					if (mask & (1 << i))
						{
							tmp *= a[i];
							cnt++;
						}
				}
			
			if (cnt & 1)
				ans -= n / tmp;
			else
				ans += n / tmp;

			if (!pi)
				{
					tmp *= p;
					if (cnt & 1)
						ans1 -= n / tmp;
					else
						ans1 += n / tmp;
				}
		}

	cout << ans << ' ';

  	if (!pi)
  		cout << ans1 << endl;
  	else
  		cout << 0;

}
