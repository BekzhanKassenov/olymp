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

int p;

bool check(int n)
{
	int k = n;
	for (int j = 0; j < p - 2; j++)
		{
			if ((n - 1 + p) % p == 0)
				return false;

			n = (n *  k) % p;
		}

   	return ((n - 1 + p) % p == 0);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> p;

	int ans = 0;

	for (int i = 1; i < p; i++)
		{
			if (check(i))
				ans++;
		}

	cout << ans;	

	return 0;
}
