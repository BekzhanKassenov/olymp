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

long long C[65][65];

void calc()
{
	for (int i = 0; i <= 64; i++)
		{
			C[i][i] = C[i][0] = 1;

			for (int j = 1; j < 64; j++)
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
}

int check(long long n)
{
	int ans = -1;

	while (n)
		{
			ans ++;
			n >>= 1;
		}

	return ans;
}

long long solve(long long n, int st)
{
	int a = check(n);
	   
	long long ans = 0;

	while (a && st)
		{
			if (n & (1ll << a))
				ans += C[a][st];

			st--;
			a--;
		}

	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	long long n, t;

	cin >> n >> t;

	if (t == 1)
		{
			cout << 1;
			return 0;
		}

	long long q = check(t);

	if (t != (1ll << q))
		{
			cout << 0;
			return 0;
		}

	calc();

	q++;

	long long ans = solve(n, q);

	cout << ans;	

	return 0;
}
