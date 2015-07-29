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
#define sqr(x) (x) * (x)1
#define INF (ll) (1e18)
#define MOD (1000 * 1000 * 1000 + 7)
#define ull unsigned long long
#define ll long long     

ll gcd(ll q, ll z)
{
	if (q == z)
		return q;

	if (q == 0 || z == 0)
		return (q + z);

	if (q < z)
		return gcd(z % q, q);

	return gcd(q % z, z);
}

ll lcm(ll q, ll z)
{
	return ((q / gcd(q, z)) * z);
}

ll a, b, k;

ll make(ll aa, ll ba)
{
	
	vector <ll> dp((int)(ba - aa + 10), INF);

	cerr << "OK" << endl;

	dp[0] = 0;

	for (ll i = aa; i <= ba; i++)
		{
			int l = i - aa;
			dp[l + 1] = min(dp[l + 1], dp[l] + 1);

			for (int j = 2; j <= k; j++)
				{
					if (i % j == 0)
						{
							for (int w = 1; w < j; w++)
								if (i + w <= ba)
									{
										dp[(int)(i + w - aa)] = min(dp[(int)(i + w - aa)], dp[(int)l] + 1);
									}
						}
				}
		}

	//cout << dp[ba - aa] << endl;

	return dp[(int)(ba - aa)];
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> a >> b >> k;

	ll ans = 0;

	if (a == b)
		{
			cout << 0;
			return 0;
		}

	ll t = 1;

	for (int i = 2; i <= k; i++)
		t = lcm(t, i);

	if ((a - b) < t)
		{
			cout << make(b, a);
			return 0;
		}

	if (a % t != 0)
		{
			cerr << "asdas" << endl;
			ans += make(a - a % t, a);
			a -= a % t;
		}

	if (b % t != 0)
		{
			ans += make(b, b - b % t + t);
			cerr << "asdas" << endl;
			b += t - b % t;
			cerr << "asdas" << endl;
		}

	if (a != b)
		{
			cerr << "Asdas" << endl;
			ll tmp = make(0, t);

			cerr << tmp << endl;

			ans += ((a - b) / t) * tmp;
			cerr << "asdasd" << endl;
		}

	cout << ans;
	return 0;
}
