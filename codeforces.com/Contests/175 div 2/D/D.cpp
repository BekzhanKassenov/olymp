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
		freopen("out", "w", stdout);
	#endif

	int prec[9] = {1, 3, 15, 133, 2025, 37851, 1030367, 36362925, 1606008513};

	int n;

	cin >> n;

	if (!(n & 1))
		{
			cout << 0;
			return 0;
		}

	long long ans = 1;

	for (int i = 1; i <= n; i++)
		ans = (ans * i) % MOD;

	ans = (ans * prec[n >> 1]) % MOD;

	cout << ans;	

	return 0;
}
