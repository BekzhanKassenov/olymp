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

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);

	#endif

	int bal = 0;

	string s;

	cin >> s;

	int mx = 0;
	int mn = 0;

	for (int i = 0; i < (int)s.length(); i++)
		{
			if (s[i] == '+')
				bal++;
			else
				bal--;

			mx = max(mx, bal);
			mn = min(mn, bal);	
		}

	cout << mx - mn;

	return 0;
}
