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

	ios_base :: sync_with_stdio(false);

	int n, k;

	cin >> n >> k;
	
	vector <int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int l = 0, r = 0;

	long long ans = 0;

	bool flag = false;

	map <int, int> m;

	int what = -1;

	while (l < n || r < n)
		{	
			if (flag)
				{
					ans += (n - r + 1);
					
					m[a[l]]--;
					
					if (m[a[l]] < k && a[l] == what)
						flag = false;

					l++;
				}
			else
				{
					if (r == n)
						break;

					while (!flag && r < n)
						{
							m[a[r]]++;

							if (m[a[r]] >= k)
								{
									what = a[r];
									flag = true;
								}	

							r++;
						}
				}	

		 	//cout << l << ' ' << r << endl;
		}
		
  	cout << ans;

	return 0;
}
