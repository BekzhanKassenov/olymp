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

ll pow_mod(ll n, int st)
{
	if (st == 0)
		return 1;

	if (st & 1) {
		return (n * pow_mod(n, st - 1)) % MOD;
	}
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

	int n, k;

	cin >> n >> k;

	ll ans = pow_mod(n - k, n - k);

	ll tmp = pow_mod(k, k - 1);

	cout << ((ans * tmp) % MOD);

	return 0;
}
