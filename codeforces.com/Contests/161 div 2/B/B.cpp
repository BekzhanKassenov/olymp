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

	int n, k;

	cin >> n >> k;

	if (k > n)
		{
			cout << -1;
			return 0;
		}

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	vector <PII> tmp;

	tmp.push_back(MP(a[0], 1));

	for (int i = 1; i < n; i++)
		{
			if (a[i] == tmp.back().F)
				tmp.back().S++;
			else
				tmp.push_back(MP(a[i], 1));
		}

	int cnt = 0;

	int i = tmp.size() - 1;

	for (; i >= 0; i--)
		{
			cnt += tmp[i].S;

			if (cnt > k)
				{
					cout << -1;
					return 0;
				}

			if (cnt == k)
				break;
		}

	if (cnt == k)
		{
			cout << tmp[i].F << ' ' << tmp[i].F;
		}
	else
		cout << -1;	

	return 0;
}
