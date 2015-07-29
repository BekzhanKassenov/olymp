#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int x, y, x1, y1, x2, y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	int xv1 = x2 - x1;
	int yv1 = y2 - y1;
	int xv2 = x - x1;
	int yv2 = y - y1;
	if (xv1 * yv2 - yv1 * xv2 == 0)
		if (xv1 * xv2 + yv1 * yv2 >= 0)
			{
				cout << "YES";
				return 0;
			}
	cout << "NO";
	return 0;
}
