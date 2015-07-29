#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

struct Point
{
	double x, y;

	Point() : x(0), y(0) {}

	Point(double x, double y) : x(x), y(y) {}
};

istream& operator >> (istream& c, Point& p)
{
	c >> p.x >> p.y;
	return c;
}

ostream& operator << (ostream& c, Point& p)
{
	c << p.x << ' ' << p.y;
	return c;
}

Point a[4];

int main()
{
	freopen("four.in", "r", stdin);
	freopen("four.out", "w", stdout);

	for (int i = 0; i < 4; i++)
		cin >> a[i];


}
