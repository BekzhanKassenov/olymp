#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define sqr(x) (x) * (x)
#define EPS 1e-10

int comp(double a, double b)
{
	if (fabs(a - b) < EPS)
		return 0;

	else
		if (a - b > EPS)
			return 1;
		else
			return -1;
}

int n;

struct point
{
	double x, y;

	point() {}

	point(double a, double b) 
		{
			x = a;
			y = b;
		}

	void read()
		{
			scanf("%lf%lf", &x, &y);
		}

	void print()
		{
			printf("%.4lf %.4lf\n", x, y);
		}

	point operator + (point a)
		{
			return point(a.x + x, a.y + y);
		}

	point operator - (point a)
		{
			return point(x - a.x, y - a.y);
		}

	double operator * (point a)
		{
			return x * a.y - a.x * y;
		}	

	double get_len()
		{
			return sqrt(sqr(x) + sqr(y));
		}
};

double area;

vector <point> mn;

void get_line(double &a, double &b, double &c, point p, point q) 
	{
		a = p.y - q.y;
		b = q.x - p.x;
		c = -(a * p.x + b * p.y);
	}

double check(point p, int pos)
{
	double tmpArea = 0;

	int cur = 0;

	double ans = 1e10;
	for (int i = pos + 1; cur < n; i++)
		{
			tmpArea += fabs((mn[i] - p) * (mn[(i + 1) % n] - p));
			cur++;
			if (comp(tmpArea + tmpArea, area) == 0)
				ans = (mn[(i + 1) % n] - p).get_len();
		}
	return ans;
}

point make_len(point a, double len)
{
	double d = a.get_len();
	len = d / len;
	a.x /= d;
	a.y /= d;
	a.x *= len;                      
	a.y *= len;
	return a;
}

double get_ans(point a, int pos)
{
	double tmpArea = 0;

	int cur = pos + 1;
	                    
	for (int i = pos + 1; cur < n; i++)
		{
			tmpArea += (fabs((mn[i % n] - a) * (mn[(i + 1) % n] - a))) / 2;
			cur++;
			if (comp(tmpArea, area - tmpArea) == 0)
				return (mn[(i + 1) % n] - a).get_len();
		}

	return 1e10;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	scanf("%d", &n);

	mn.resize(n);

	for (int i = 0; i < n; i++)
		mn[i].read();


	for (int i = 1; i < n; i++)
		{
			area += fabs((mn[i] - mn[0]) * (mn[(i + 1) % n] - mn[0]));
		}

	area /= 2;

	double ans = 1e+10;

	for (int i = 0; i < n; i++)
		{
			double tmp = check(mn[i], i);
			if (comp (tmp, ans) == -1)
				ans = tmp;
		}

	for (int i = 0; i < n; i++)
		{
			double a, b, c;
			get_line(a, b, c, mn[i], mn[(i + 1) % n]);
			point vect = point(b, -a);

			double dst = vect.get_len();

			for (double len = 0.00001; comp(len, 1) != 1; len += 0.001)
				{
					point tmp = make_len(vect, len);
					point curp = mn[i] + tmp;

					double qwe = check(curp, i);

					if (qwe != 1e10 && comp(qwe, ans) == -1)
						{
							ans = qwe;
							continue;
						}

					double cur = get_ans(curp, i);

					if (comp(cur, ans) == -1)
						ans = cur;
				}
		}

	printf("%.5lf", ans);
	return 0;
}
