#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct point
{
	int x, y;

	point() {}

	point(int p, int z)
		{
			x = p;
			y = z;
		}

	void read()
		{
			char c;
			cin >> c;

			x = c - 'a';
			
			cin >> c;

			y = c - '0' - 1;
		}

	bool operator == (point a)
		{
			return (a.x == x && a.y == y);
		}

	bool operator != (point a)
		{
			return ((a.x != x) || (a.y != y));
		}
};

point operator + (point a, point b)
{
	a.x += b.x;
	a.y += b.y;
	return a;
}


bool used[8][8];

point a[8];

point f, k1, k2;

bool ok(point a)
{
	if (a.x >= 0 && a.x < 8)
		if (a.y >= 0 && a.y < 8)
			return true;

	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int uk = 0;

	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			{
				if (i != 0 || j != 0)
					{
						a[uk++] = point(i, j);
					}
			}

	k1.read();

	f.read();

	k2.read();

	point tmp;

	for (int i = 0; i < 8; i++)
		{
			tmp = f + a[i];

			while (ok(tmp))
				{
					used[tmp.x][tmp.y] = true;
					
					//cout << tmp.x << ' ' << tmp.y << endl;

					if (tmp == k1 || tmp == k2)
						break;

					tmp = tmp + a[i];
				}
		}

	if (used[k2.x][k2.y])
		cout << "YES";
	else
		cout << "NO";

}
