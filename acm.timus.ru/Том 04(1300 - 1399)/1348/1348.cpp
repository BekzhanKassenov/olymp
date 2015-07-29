#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

#define sqr(x) (x) * (x)

struct point
{
	double x; 
	double y;

	point() 
		{
			x = 0, y = 0;
		}

	point(double qx, double qy)
		{
			x = qx, y = qy;
		}

	bool operator == (point a)
		{
			return (x == a.x && y == a.y);
		}

	point operator - (point a)
		{
			return point(x - a.x, y - a.y);
		}             

	double len()
		{
			return sqrt(sqr(x) + sqr(y));
		}

	void print()
		{
			printf("%4lf  %.4lf\n", x, y);
		}
};

double calc_all(point a, point b, point c, double l)
{
	/*a.print();
	b.print();
	c.print();*/

	point p1 = a - c, p2 = b - c;

	double dist_to_a = p1.len();

	double dist_to_b = p2.len();

	/*p1.print();

	p2.print();*/

	double ans = max(dist_to_a, dist_to_b);

	ans -= l;

	ans = max(0.0, ans);

	return ans;
}

double calc_dist(point a, point b, point c, double l)
{
	if (a == b)
		return max(0.0, ((c - a).len() - l));

	/*a.print();
	b.print();
	c.print();*/
		
	point p1 = a - b;
	point p2 = c - b;

  	double skal1 = p1.x * p2.x + p1.y * p2.y;

  	p1 = b - a;
  	p2 = c - a;

  	double skal2 = p1.x * p2.x + p1.y * p2.y;

  	if (skal1 <= 0 || skal2 <= 0)
  		{
  			return max(0.0, min((a - c).len(), (b - c).len()) - l);
  		}

  	double A = a.y - b.y;

  	double B = b.x - a.x;

  	double C = b.x * a.y - a.x * b.y;

  	return max(0.0, (fabs(A * c.x + B * c.y + C) / sqrt(sqr(A) + sqr(B))) - l);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	point a, b, c;

	double l;

	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> l;

	double dist1 = calc_dist(a, b, c, l);

	double dist2 = calc_all(a, b, c, l);
	
	printf("%.2lf\n%.2lf", dist1, dist2);
	
	return 0;
}
