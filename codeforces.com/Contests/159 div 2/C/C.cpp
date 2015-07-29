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
#include <cassert>
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
#define pi 3.1415926535 
#define EPS 1e-8

int comp(double a, double b)
{
	if (fabs(a - b) < EPS)
		return 0;

	if (a - b > EPS)
		return 1;

	return -1;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	vector <double> a(n), x(n), y(n);

	for (int i = 0; i < n; i++)
		{
			cin >> x[i] >> y[i];

			double t1 = x[i], t2 = y[i];

			a[i] = atan2(t2, t1);
		}

	for (int i = 0; i < n; i++)
		{
			//cout << a[i] << ' ' << atan2(y[i], x[i]) << endl;
			assert(comp(a[i], atan2(y[i], x[i])) == 0);	
		}

	sort(a.begin(), a.end());

	double ans = 10;

	//printf("%.6lf ", a[0]);

	for (int i = 1; i < n; i++)
		{
			double tmp = 2 * pi - (a[i] - a[i - 1]);
			//printf("%.6lf ", (a[i] * 360) / (2 * pi));
			if (comp(tmp, ans) == -1)
				ans = tmp;
		}

	double tmp = a[n - 1] - a[0];

	if (comp(tmp, ans) == -1)
		ans = tmp;

	printf("%.6lf", (ans * 360) / (2 * pi));

	return 0;
}
