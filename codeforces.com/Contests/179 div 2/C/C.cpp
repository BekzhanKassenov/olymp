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

	int n, m, k;

	cin >> n >> m >> k;

	vector <ll> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector <ll> l(m), r(m), d(m);

	for (int i = 0; i < m; i++)
		cin >> l[i] >> r[i] >> d[i];

	vector <pair <ll, ll> > flag(m);

	int x, y;

	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		flag[x - 1].F++;
		flag[y - 1].S++;
	}

	ll cnt = 0;

	for (int i = 0; i < m; i++) {
		cnt += flag[i].F;
		d[i] *= cnt;
		cnt -= flag[i].S;
	}

	flag.assign(n, MP(0, 0));

	for (int i = 0; i < m; i++) {
		flag[l[i] - 1].F += d[i];
		flag[r[i] - 1].S += d[i];
	}

	cnt = 0;

	for (int i = 0; i < n; i++) {
		cnt += flag[i].F;
		a[i] += cnt;
		cnt -= flag[i].S;
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	return 0;
}
