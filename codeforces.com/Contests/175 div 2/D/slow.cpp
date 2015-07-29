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
		freopen("out", "w", stdout);
	#endif

	int n;

	cin >> n;

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		a[i] = i;

	vector <int> b = a;

	int ans = 0;

	do
		{
			do
				{
					vector <int> c(n);

					for (int i = 0; i < n; i++)
						c[i] = (a[i] + b[i]) % n;

					sort(c.begin(), c.end());

					bool flag = true;

					for (int i = 0; i < n; i++)
						if (c[i] != i)
							flag = false;

					ans += flag;

					if (ans >= MOD)
						ans -= MOD;
				}
			while (next_permutation(b.begin(), b.end()));

			sort(b.begin(), b.end());
		}
	while (next_permutation(a.begin(), a.end()));

	cout << ans;

	return 0;
}
