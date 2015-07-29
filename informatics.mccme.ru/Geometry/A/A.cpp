#include <iostream>
#include <cstdio>

using namespace std;

#define abs(x) (x < 0) ? (-x) : x

int kos(int x1, int y1, int x2, int y2)
{
	return x1 * y2 - y1 * x2;
}

int main()
{
	int x, y, x1, y1, x2, y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	double k = (double)(abs(kos(x1 - x, y1 - y, x2 - x, y2 - y))) / 2;
	printf("%.10lf", k);
	return 0;
}
