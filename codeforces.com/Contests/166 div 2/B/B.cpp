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

vector <bool> prime(110000, true);

vector <int> primes;

void build()
{
	prime[0] = prime[1] = false;

	for (int i = 2; i <= 110000; i++)
		{
			if (prime[i])
				{
					primes.push_back(i);

					if (i * 1ll * i <= 110000)
						for (int j = i * i; j <= 110000; j += i)
							prime[j] = false;
				}
		}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, m;
	
	cin >> n >> m;

	vector <vector <int> > a(n, vector <int> (m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	long long ans = INF;

	build();

	for (int i = 0; i < n; i++)
		{
			long long tmp = 0;

			for (int j = 0; j < m; j++)
				{   
					if (!prime[a[i][j]])
						tmp += (*upper_bound(primes.begin(), primes.end(), a[i][j])) - a[i][j];
				}

			ans = min(ans, tmp);	
		}

	for (int j = 0; j < m; j++)
		{
			long long tmp = 0;

			for (int i = 0; i < n; i++)
				{
					if (!prime[a[i][j]])
						tmp += (*upper_bound(primes.begin(), primes.end(), a[i][j])) - a[i][j];

				}

			ans = min(ans, tmp);	

		}	

	cout << ans;	

	return 0;
}
