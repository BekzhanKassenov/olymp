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
#define EPS 1e-10

bool check(vector <int> a)
{
	if (a[1] > a[0] && a[1] > a[2])
		return true;

	if (a[1] < a[0] && a[1] < a[2])
		return true;

	return false;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int Min = 0, Max = 0;

	for (int i = 1; i < n; i++)
		{
			if (a[Min] > a[i - 1])
				Min = i - 1;

			if (a[Max] < a[i - 1])
				Max = i - 1;

			vector <int> tmp;

			if (Min < Max)
				{
					tmp.push_back(a[Min]);
					tmp.push_back(a[Max]);
					tmp.push_back(a[i]);
				}

			else
				{
					tmp.push_back(a[Max]);
					tmp.push_back(a[Min]);
					tmp.push_back(a[i]);
				}

			if (check(tmp))
				{
					cout << 3 << endl;
					if (Min < Max)
						{
							cout << Min + 1 << ' ' << Max + 1 << ' ' << i + 1;
						}
					else
						{
							cout << Max + 1 << ' ' << Min + 1 << ' ' << i + 1;
						}
					return 0;
				}
		}

	cout << 0;
	return 0;
}
