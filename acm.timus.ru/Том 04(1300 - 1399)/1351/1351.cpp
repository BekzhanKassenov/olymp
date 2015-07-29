#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

struct Point
{
	int x, y;

	Point (int x, int y) : x(x), y(y) {}

	Point () {}

	int operator * (Point &a)
		{
			return x * a.y - y * a.x;
		}

	int dist()
		{
			return (x * x + y * y);
		}
};

istream& operator >> (istream& c, Point& p)
{
	c >> p.x >> p.y;

	return c;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int d;

	cin >> d;

	d *= d;

	Point l, r;

	cin >> l >> r;

	if (l * r < 0)
		swap(l, r);

	int n;

	cin >> n;

	Point tmp;

	for (int i = 0; i < n; i++)
		{
			cin >> tmp;

			if (l * r == 0)
				{
					if (l.x * tmp.x + l.y * tmp.y > 0 && l * tmp == 0 && tmp.dist() <= d)
						cout << "YES" << endl;
					else
						cout << "NO" << endl;	
				}
			else
				if (l * tmp >= 0 && tmp * r >= 0 && tmp.dist() <= d)
					cout << "YES" << endl;
				else
					cout << "NO" << endl;	
		}

	return 0;
}
                         