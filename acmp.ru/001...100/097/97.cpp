#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct Point
{
	int x, y;
    
    Point() {}

	Point(int x, int y): x(x), y(y) {}

	Point operator + (int n)
		{
			return Point(x + n, y + n);
		}
};

bool in(Point a, struct pr b);

struct pr
{
    Point first, second;

	pr() {}

	bool intersects(pr a) const
		{
			if (in(first, a))	
				return true;

			if (in(second, a))	
				return true;

			Point tmp = Point(first.x, second.y);

			if (in(tmp, a))	
				return true;

			tmp = Point(second.x, first.y);

			if (in(tmp, a))	
				return true;

			return false;
		}

 	void increase(int n)
 		{
 			first = first + (-n);
 			second = second + n;
 		}
};

inline bool in(Point a, pr b)
{
	if (a.x >= b.first.x && a.x <= b.second.x)
		if (a.y >= b.first.y && a.y <= b.second.y)
			return true;

	return false;
}

istream& operator >> (istream& c, Point& p)
{
	c >> p.x >> p.y;
	return c;
}

istream& operator >> (istream& c, pr& p)
{
	c >> p.first >> p.second;

	int x = min(p.first.x, p.second.x);
	int y = min(p.first.y, p.second.y);

	int x1 = max(p.first.x, p.second.x);
	int y1 = max(p.first.y, p.second.y);
    
    p.first = Point(x, y);
    p.second = Point(x1, y1);

    return c;
}

vector <int> color;

int get(int n)
{
	if (color[n] == n)	
		return n;

	return (color[n] = get(color[n]));	
}

inline void dsu_union(int a, int b)
{
	a = get(a), b = get(b);

	if (a != b)
		color[a] = b;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	color.resize(n);

	vector <pr> a(n);

	for (int i = 0; i < n; i++)
		color[i] = i;

	int r;

	for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			cin >> r;

			a[i].increase(r);
		}

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				{
					if (a[i].intersects(a[j]))
						dsu_union(i, j);
				}
		}

	int ans = 0;

	for (int i = 0; i < n; i++)
		if (color[i] == i)
			ans++;

	cout << ans;

	return 0;	
}
