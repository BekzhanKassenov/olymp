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
#define int long long

int per(PII a, PII b)
{
	int cnt = 1;

	for (int i = a.F + 1; i <= b.F; i++)
		{
			if (a.S / cnt == 0)
				return b.S;


			cout << a.F << ' ' << b.F << endl;

			cnt *= 4;
		}

	return (max(a.S / cnt + (a.S % cnt != 0), b.S));
}

main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio(false);

	int n;

	cin >> n;

	vector <PII> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i].F >> a[i].S;

	sort(a.begin(), a.end());

	int tmp = a[0].S;

	for (int i = 1; i < n; i++)
		{
			tmp = per(MP(a[i - 1].F, tmp), a[i]);
		}

	int ans = 0;

	for (;tmp > 0;)
		{
			tmp = per(MP(a.back().F + ans, tmp), MP(a.back().F + ans + 1, 0));

			if (tmp == 0)
				break;

			ans++;
		}

	cout << a.back().F + ans + 1;	
}
