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
#define File "contest"

main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int n;

	cin >> n;
	vector <int> a(n);

	int sum = 0;

	for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			sum += a[i];
		}

	vector <int> ans(n);	

	for (int mask = 1; mask < (1 << n) - 1; mask++)
		{
			int tmps = 0;
			for (int i = 0; i < n; i++)
				if (mask & (1 << i))
					{
						tmps += a[i];
					}

			if (tmps > sum - tmps)
				{
					for (int i = 0; i < n; i++)
						if (mask & (1 << i))
							ans[i] ++;
				}
		}	

	for (int i = 0; i < n; i++)
		cout << ans[i] << endl;

	//return 0;
}
