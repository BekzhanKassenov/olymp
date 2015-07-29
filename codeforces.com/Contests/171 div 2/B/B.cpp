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

	int n, t;

	cin >> n >> t;

	vector <ll> a(n + 1);

	for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			a[i] += a[i - 1];
		}

	int uk = 1;

	int ans = 0;

	for (int i = 1; i <= n; i++)
		{
			while (a[i - 1] + t >= a[uk] && uk < n)
				uk++;

			//cout << i << ' ' << uk << endl;	

			if (a[i - 1] + t >= a[uk])
				ans = max(ans, uk - i + 1);
			else
				ans = max(ans, uk - i);
		}

	cout << ans;	

	return 0;
}
