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

	vector <vector <int> > dp(101, vector <int> (2501));

	dp[0][0] = 1;

	for (int i = 1; i <= 100; i++)
		{
			for (int j = 0; j <= 2500; j++)
				for (int k = 0; k <= min(25, j); k++)
					{
						dp[i][j] += dp[i - 1][j - k];
						dp[i][j] %= MOD;
					}
		}

	ios_base :: sync_with_stdio(false);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		{
			string s;

			cin >> s;

			int len = s.size();

			int cnt = 0;

			for (int j = 0; j < len; j++)
				cnt += s[j] - 'a';

			cout << dp[len][cnt] - 1 << endl;
		}

	return 0;
}
