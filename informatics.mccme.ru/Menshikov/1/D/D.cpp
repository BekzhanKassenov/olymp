#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int kos(int x1, int y1, int x2, int y2)
{
	return x1 * y2 - y1 * x2;
}

int main()
{
	int x, y, x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x >> y;
	int s1 = abs (kos (x1 - x3, y1 - y3, x2 - x3, y2 - y3));
	int s2 = abs (kos (x1 - x, y1 - y, x2 - x, y2 - y)) + abs (kos (x1 - x, y1 - y, x3 - x, y3 - y)) + abs (kos (x2 - x, y2 - y, x3 - x, y3 - y));

	if (s1 == s2)
	 	cout << "In";
	else
		cout << "Out";
}

