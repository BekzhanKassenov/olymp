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
#define EPS 1e-1
#define File "rag" 

struct point
{
	double x, y;

	point(double a, double b)
		{
			x = a;
			y = b;
		}

	point()  {}

	point operator - (point a)
		{
			return point(x - a.x, y - a.y);
		}

	double operator * (point a)
		{
			return x * a.y	- y * a.x;
		}
				
};

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int w, h;

	cin >> w >> h;

	int n;

	cin >> n;

	vector <point> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i].x >> a[i].y;

	point v = point(w, h);

	double ans = 0;

	for (int i = 0; i < n; i++)
		{
			point q = a[i] - v;
			point z = a[(i + 1) % n] - v;
			ans += (q * z);
		}         
	ans /= 2;

	printf("%.10lf", ans);


	return 0;
}
