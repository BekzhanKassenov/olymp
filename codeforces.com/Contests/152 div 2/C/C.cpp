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
#include <cmath>
#include <algorithm>
#include <cstdlib>
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

int comp(int a, int b)
{
	if (fabs(a - b) < EPS)
		return 0;

	if (a - b > EPS)
		return 1;

	return -1;
}

void get_line(double &a, double &b, double &c, double x, double y, double _x, double _y) 
{
	a = y - _y;
	b = _x - x;
	c = _y * x - _x * y;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	double y, _y, yw, xb, yb, r;

	cin >> y >> _y >> yw >> xb >> yb >> r;

	yb += 2 * (yw - yb);

	y += r;

	double a, b, c;

  	get_line(a, b, c, y, 0, yb, xb);

  	double len = sqrt(sqr(a) + sqr(b));

  	a /= len;
  	b /= len;
  	c /= len;

  	double dst = (b * _y + c);

  	if (comp(dst, r) < r)
  		{
  			cout << -1;
  			return 0;
  		}


  	yw -= r / 2;

  	yb -= 2 * (yb - yw);

  	double q = yw - yb;

  	double z = yw - y;

  	double fnd = (xb * q) / (q + z);

  	printf("%.14lf", fnd);

	return 0;
}
