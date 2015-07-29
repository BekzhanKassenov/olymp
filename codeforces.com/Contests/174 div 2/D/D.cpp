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
#include <cstring>
#include <iomanip>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define sqr(x) (x) * (x)
#define MOD (1000 * 1000 * 1000 + 7)
#define ull unsigned long long
#define ll long long

ll a[200010];

ll dp[2][200010];

bool inst[2][200010];

int n;

ll INF = (1000000ll * 1000000ll * 1000000ll * 2ll);

ll dfs(bool flag, int pos)
{
	if (inst[flag][pos])
		return INF;

	if (flag && pos == 1)
		{
			dp[flag][pos] = INF;
			return dp[flag][pos];
		}

	if (dp[flag][pos] != -1)
		return dp[flag][pos];

	inst[flag][pos] = true;

	int tmp;
	
	if (flag)
		tmp = pos + a[pos];
	else
		tmp = pos - a[pos];

	dp[flag][pos] = a[pos];

	if (tmp > n || tmp <= 0)
		{
			inst[flag][pos] = false;
			return (dp[flag][pos]);
		}

	ll q = dfs(1 - flag, tmp);

	if (q != INF)
		dp[flag][pos] += q;
	else
		dp[flag][pos] = INF;	

	inst[flag][pos] = false;

	return dp[flag][pos];	
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio(false);

	cin >> n;

	memset(dp, -1, sizeof dp);

	for (int i = 2; i <= n; i++)	
		cin >> a[i];

	for (int i = 2; i <= n; i++)
		dfs(false, i);
	
	dp[false][1] = 1;

	for (int i = 1; i <= n - 1; i++)
		{
			ll tmp = dp[false][i + 1];

			if (tmp == INF)
				cout << -1;
			else
				cout << tmp + i;

			cout << endl;	
		}

	return 0;
}
