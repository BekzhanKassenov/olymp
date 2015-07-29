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

int log2(long long n)
{
	int ans = 0;

	while ((1ll << ans) <= n)
		ans++;

	return ans;
}

long long to_int(vector <int>& a)
{
	long long ans = 0;

	for (int i = a.size() - 1; i >= 0; i--)
		ans = ans * 2 + a[i];

	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	long long l, r;

	cin >> l >> r;

	int n = log2(r);

	long long ans = l ^ r;

	long long ll = l, rr = r;

	for (int i = n - 1; i >= 0; i--)
		{
			if (!(ans & (1ll << i)))
				{
					if (rr & (1ll << i))
						{
							if (rr - (1ll << i) >= l)
								rr -= (1ll << i);
						}
					else
						{
							if (ll + (1ll << i) <= r)
								ll += (1ll << i);
						}	
				}
		}

	cout << (ll ^ rr);

	return 0;
}
