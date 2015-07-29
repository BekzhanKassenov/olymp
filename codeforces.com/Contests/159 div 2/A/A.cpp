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

	int n, m, k;

	cin >> n >> m >> k;

	if (m <= k)
		{
			cout << 0;
			return 0;
		}

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int ans = 0;

	sort(a.rbegin(), a.rend());

	int cnt = 0;

	for (int i = 0; i < n; i++)
		{
			cnt += a[i];
			ans++;
			k--;
			if (k < 0)
				cnt--;

			if (cnt >= m || m - cnt <= k )
				{
					cout << ans;
					return 0;
				}
		}

	if (cnt < m)
		cout << -1;
	else
		cout << ans;

	return 0;
}
