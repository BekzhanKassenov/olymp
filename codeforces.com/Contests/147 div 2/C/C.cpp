/*********************************************
**       Solution by Bekzhan Kasenov        **
**********************************************/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <limits.h>
#include <ctime>


using namespace std;

#define abs(x) (x < 0) ? (-x) : x
#define sqr(x) (x) * (x)
#define INF 2000000000
#define EPS 10e-14
#define PII pair <int, int>
#define PIS pair <int, string>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define VII vector <VI>
#define LL long long
#define ULL unsigned long long

vector <int> cnt;

int a, b, k;

bool check(int l)
{
	for (int x = a; x <= b - l + 1; x++)
		{
			int tmp = cnt[x + l - 1] - cnt[x - 1];
			if (tmp < k)
				return false;
		}
	return true;

}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> a >> b >> k;

	vector <bool> prime(b + 1, true);

	prime[0] = prime[1] = false;

	for (int i = 0; i <= b; i++)
		{
			if (prime[i] && i * 1ll * i <= b)
				{
					for (int j = i * i; j <= b; j += i)
						prime[j] = false;
				}
		}

	cnt.resize(b + 1);

	for (int i = a; i <= b; i++)
		cnt[i] = cnt[i - 1] + (prime[i]);

	int l = 1, r = b - a + 1;

	int ans = 2E+9;

	while (l <= r)
		{
			int m = (l + r) / 2;

			//cout << l << ' ' << r << ' ' << m << endl;

			if (check(l))
				ans = min(ans, l);

			if (check(r))
				ans = min(ans, r);

			if (check(m))
				{
					ans = min(ans, m);
					r = m - 1;
				}
			else
				l = m + 1;

			if (l == r)
				if (check(l))
					ans = min(ans, l);
		}

	if (ans != 2E+9)
		cout << ans;
	else
		cout << -1;

	return 0;
}
