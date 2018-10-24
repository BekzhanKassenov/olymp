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

inline bool intersects(int x1, int x2, int x3, int x4);

struct pr
{
    Point first, second;

	pr() {}

	bool intersects(pr a) const
		{
            if (::intersects(first.x, second.x, a.first.x, a.second.x))
                if (::intersects(first.y, second.y, a.first.y, a.second.y))
                    return true;

            return false;
		}

 	void increase(int n)
 		{
 			first = first + (-n);
 			second = second + n;
 		}
};

inline bool intersects(int x1, int x2, int x3, int x4) 
{
    return x2 >= x3 && x4 >= x1;
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
