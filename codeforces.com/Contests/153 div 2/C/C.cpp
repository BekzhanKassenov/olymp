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

	int n, d;

	cin >> n >> d;

	VI a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	VI uk(n, -1);

	for (int i = 0; i < n; i++)
		{
			VI :: const_iterator it = upper_bound(a.begin(), a.end(), a[i] + d);

			uk[i] = n - (a.end() - it);
		}

	ll ans = 0;

	for (int i = 0; i < n; i++)
		{
			ans += ((uk[i] - i - 1) * 1ll * (uk[i] - i - 2)) / 2;
		}

  	cout << ans;


	return 0;
}
