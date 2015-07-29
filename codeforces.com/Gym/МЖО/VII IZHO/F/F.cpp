/********************************************
***     Solution by Bekzhan Kassenov      ***
********************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

#define sqr(x) (x) * (x)
#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define VII vector <VI>
#define ll long long
#define ull unsigned long long
#define INF
#define MOD
#define EPS
#define File "skyline"

int n;

vector <int> a;

int get(int len)
{
	int ans = 7 * (len / 3);

	if (len % 3 == 2)
		ans += 5;
	if (len % 3 == 1)	
		ans += 3;

	return ans;
}

int solve(int l, int r, int h)
{
	if (l > r)
		return 0;

	int ans = 0;

	if (l == r)
		{
			ans = 3 * (a[l] - h);
		}
  	else
  		{
			int pos = l;

			for (int i = l + 1; i <= r; i++)
				if (a[pos] > a[i])
					pos = i;

			ans = get(r - l + 1);

			ans *= a[pos] - h;

			cout << "aSDAS" << ' ' << l << ' ' << r << ' ' << ans << endl;
			ans += solve(l, pos - 1, a[pos]);
		
			ans += solve(pos + 1, r, a[pos]);
      }

   cout << l << ' ' << r << ' ' << ans << endl;
	return ans;
}

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	cin >> n;
	
	a.resize(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << solve(0, n - 1, 0);

	return 0;
}
