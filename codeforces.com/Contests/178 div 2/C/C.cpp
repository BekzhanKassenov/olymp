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

ll pow_mod(ll n, int st) {
	if (st <= 0)
		return 1;

	if (st & 1)
		return (n * pow_mod(n, st - 1)) % MOD;
	else {
		ll b = pow_mod(n, st >> 1);
		return (b * b) % MOD;
	}	
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, m;

	cin >> n >> m;

	vector <int> a(m);

	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	ll ans = 1;

	for (int i = 1; i < m; i++) {
		ans = (ans * pow_mod(2, a[i] - a[i - 1] - 1)) % MOD;
	}

	if (a[0] != 1)
		ans = (ans * (a[0] - 1)) % MOD;

	if (a[m - 1] != n)
		ans = (ans * (n - a[m - 1])) % MOD;

	cout << ans;

	return 0;
}
