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

	int n, m;

	cin >> n >> m;

	if (n == 0 && m > 0)
		{
			cout << "Impossible";
			return 0;
		}

	if (n == 0 && m == 0)
		{
			cout << "0 0";
			return 0;
		}

	if (n > 0 && m == 0)
		{
			cout << n << ' ' << n << endl;
			return 0;
		}

	int mx = m + n - 1;

	int mn = max(m, n);

	cout << mn << ' ' << mx;	

	return 0;
}
