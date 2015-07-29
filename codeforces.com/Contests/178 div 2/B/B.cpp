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

	int n;

	cin >> n;

	vector <int> a[2];

	int sum[2] = {0};

	for (int i = 0; i < n; i++) {
		int x, y;

		cin >> x >> y;

		a[x - 1].push_back(y);
		sum[x - 1] += y;
	}

	sort(a[0].rbegin(), a[0].rend());
	sort(a[1].rbegin(), a[1].rend());

	int s1 = a[0].size();
	int s2 = a[1].size();

	int cur1 = 0, cur2 = 0;

	int ans = INF;

	for (int i = 0; i <= s1; i++) {
		for (int j = 0; j <= s2; j++) {
			if (i + 2 * j >= sum[0] - cur1 + sum[1] - cur2)
				ans = min(ans, i + 2 * j);
			
			if (j != s2)
			cur2 += a[1][j];
		}
		cur2 = 0;
		if (i != s1)
		cur1 += a[0][i];
	}

	cout << ans;

	return 0;
}
