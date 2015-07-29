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

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int m;

	cin >> m;

	int x, y;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;

		x--;

		int l = y - 1, r = a[x] - y;

		a[x] = 0;

		if (x < n - 1)
			a[x + 1] += r;

		if (x > 0)
			a[x - 1] += l;
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << endl;

	return 0;
}
