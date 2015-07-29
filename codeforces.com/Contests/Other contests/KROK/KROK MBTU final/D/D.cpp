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
#define EPS 1e-10
#define MOD (1000 * 1000 * 1000 + 7)
#define ull unsigned long long
#define ll long long

struct point
{
	double y;
	double dist;

	point(double val)
		{
			y = val;
			dist = 0;
		}

	point() 
		{
			y = dist = 0;
		}
};

int comp(double a, double b)
{
	if (fabs(a - b) < EPS)
		return 0;

	if (a - b > EPS)
		return 1;

	return -1;	
}

bool operator < (point a, point b)
{
	if (comp(a.y, b.y) == -1)
		return true;

	return false;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, m;

	double a, b;

	cin >> n >> m >> a >> b;

	vector <point> cr(n);

	for (int i = 0; i < n; i++)
		{
			cin >> cr[i].y;
			cr[i].dist = sqrt(sqr(cr[i].y) + sqr(a));
		}

	vector <point> t(m);

	for (int i = 0; i < m; i++)
		cin >> t[i].y;

	for (int i = 0; i < m; i++)
		cin >> t[i].dist;

	double q = 1e10;

	int ans1 = -1, ans = -1;

	for (int j = 0; j < m; j++)
		{
			double yw = (a / b) * t[j].y;

			int cnt = 0;

			int k = lower_bound(cr.begin(), cr.end(), point(yw)) - cr.begin();

			for (int i = max(k - 1, 0); i <= min(n - 1, k + 1); i++)
				{
					double k = cr[i].dist + sqrt(sqr(b - a) + sqr(cr[i].y - t[j].y)) + t[j].dist;
               
               		if (comp(k, q) == -1)
						{
							q = k;
							ans = i + 1;
							ans1 = j + 1;
						}
			  }
		}

	cout << ans << ' ' << ans1;
	
	return 0;
}