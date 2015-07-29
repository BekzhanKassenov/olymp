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
#define SZ size()
#define VI vector <int>

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	int n, k;
	cin >> n >> k;
	VI a(n);

	VI p(100010);

	map <int, int> m;

	for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			m[a[i]]++;
		}

	int l = 0, r = n - 1;

	int q = (int)m.size();

	if (q < k)
		{
			cout << -1 << ' ' << -1;
			return 0;
		}

	while (l <= r)
		{
			//cout << l << ' ' << r << endl;
			if (m[a[l]] == 1 && m[a[r]] == 1)
				{
					if (q == k)	
						{
							cout << l + 1 << ' ' << r + 1;
							return 0;
						}
					if (q == k + 1)
						{
							m[a[l]] --;
							l++;
							q--;
						}
					if (q > k + 1)
						{
							m[a[l]] --;
							q--;
							l++;
							
							m[a[r]]--;
							q--;
							r--;
						}
				}
			if (l > r)
				break;
			if (m[a[l]] > 1)
				{
					m[a[l]]--;
					l++;
				}
			if (m[a[r]] > 1)
				{
					m[a[r]] --;
					r--;
				}
		}
	cout << -1 << ' ' << -1;
	return 0;
}
