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

int days_in_month(int m)
{
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		return 31;

	if (m == 2)
		return 28;

	if (m == 4 || m == 6 || m == 9 || m == 11)
		return 30;
}

int date_to_days(int m, int dt)
{
	int ans = 0;

	for (int i = 1; i < m; i++)
		ans += days_in_month(i);

	ans += dt;

	return ans;
}

struct d
{
	int when,nmb;

	bool fl;

	d(int a, bool f, int b)
		{
			when = a;
			fl = f;
			nmb = b;
		}
};

bool operator < (d a, d b)
{
	if (a.when > b.when)
		return true;

	if (a.when < b.when)
		return false;

	if (!a.fl)
		return true;

	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	priority_queue <d> q;

	int n;

	cin >> n;

	int m, dt, p, t;

	for (int i = 0; i < n; i++)
		{
			cin >> m >> dt >> p >> t;

			int date = date_to_days(m, dt);

			int begin = date - t;

			q.push(d(date, true, p));

			q.push(d(begin, false, p));

		}

	int ans = 0;

	int now = 0;

	while (!q.empty())
		{
			d tmp = q.top();

			q.pop();

			if (tmp.fl)
				{
					now += tmp.nmb;
				}
			else
				{	
					if (now >= tmp.nmb)
						{
							now -= tmp.nmb;
						}

					else
						{
							ans += tmp.nmb - now;
							now = 0;
						}
				}
		}
	cout << ans;
	return 0;
}
