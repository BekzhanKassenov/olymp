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

vector <vector <int> > dp;

vector <vector <bool> > is;

int n;

string s;

void init(int n)
{
	dp.assign(n, vector <int> (n, -1));
	is.assign(n ,vector <bool> (n));
}

int calc(int l, int r)
{
	if (l > r)
		return 0;

	if (dp[l][r] != -1)
		return dp[l][r];

	if (is[l][r])	
		dp[l][r] = calc(l + 1, r) + calc(l, r - 1) - calc(l + 1, r - 1) + 1;
	else
		dp[l][r] = calc(l + 1, r) + calc(l, r - 1) - calc(l + 1, r - 1);
	
	return dp[l][r];
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> s;

	n = (int)s.length();

	init(n);

	for (int i = 0; i < n; i++)
		{
			int ll = i, rr = i;

			while (ll >= 0 && rr < n && s[ll] == s[rr])
				{
					is[ll][rr] = true;
					ll--, rr++;
				}

			ll = i, rr = i + 1;

			while (ll >= 0 && rr < n && s[ll] == s[rr])
				{
					is[ll][rr] = true;
					ll--;
					rr++;
				}
		}

	int k;

	cin >> k;

	calc(0, n - 1);

	for (int i = 0; i < k; i++)
		{
			int l, r;

			cin >> l >> r;

			cout << dp[l - 1][r - 1] << endl;
		}

	return 0;
}

