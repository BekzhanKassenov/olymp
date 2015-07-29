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

int n, m;

int cnt2;

long long ans = 1;

void do_it(int n)
{
	for (int i = 2; i <= n; i++)
		{
			int c = i;

			while (!(c & 1))
				{
					cnt2++;
					c >>= 1;
				}

			ans = (ans * c) % m;
		}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio(false);

	cin >> n;

	vector <int> a(n), b(n);

	map <int, int> mp;

	for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			mp[a[i]]++;
		}

	for (int i = 0; i < n; i++)
		{
			cin >> b[i];	
			mp[b[i]]++;
		}

	cin >> m;	

	for (map <int, int> :: iterator it = mp.begin(); it != mp.end(); it++)
		do_it(it -> S);

	int cnt = 0;

	for (int i = 0; i < n; i++)
		if (a[i] == b[i])
			cnt++;

	cnt2 -= cnt;

	for (int i = 0; i < cnt2; i++)
		ans = (ans * 2)	% m;

	cout << ans;	
		
	return 0;
}
